/*
This code allows us to create a Triggerbot hack for CSS,
in theory this will work for most games. 
Especially source based like TF2 all Counter-strikes etc.

Credits to ExcidiumDubstep for external base tutorial and Nubtik for certain code sections

Written by Fleep at http://guidedhacking.com/, feel free to check us out for many tutorials 
on cheating and join our friendly hacking community
If you end up releasing any hacks from this code they would be greatly appreciated on our GuidedHacking.
*/



/*
TO DO:
-ADD m_fFlags CHECK on enemies so we can aim appropriately


*/


#include <Windows.h>  
#include <iostream> 
#include <math.h>  
#include "HackProcess.h"
#include <vector>
#include <algorithm>    // std::sort
//Create our 'hooking' and process managing object
CHackProcess fProcess;  
using namespace std;  
//We use F6 to exit the hack
#define F6_Key 0x75
//right click
#define RIGHT_MOUSE 0x02
//Here we store the num of players and update it regularly to know how many enemies we are dealing with
//this saves us doing loops unless their necessary e.g. we have 12 players and still loop 32 times wasting our great resources
//This makes our triggerbot MUCH faster in general
int NumOfPlayers = 32;
const DWORD dw_PlayerCountOffs = 0x5CE10C;//Engine.dll

//The player base is VERY important so we know where our player info is at
//including current jump status so we can use force jumping making our bHop
const DWORD Player_Base = 0x53FB04;//0x00574560;
//The ATTACK address BELOW, WE WRITE 5 TO SHOOT OR 4 TO 
const DWORD dw_mTeamOffset = 0x98;//client
const DWORD dw_Health = 0x90;//client
//FOR the x coord we can use cl_pdump for m_vecOrigin Vector or just move around the map looking for different values
//e.g. to find y coordinate walk up ladder search up, walk down search down etc.
const DWORD dw_Pos = 0x25C;//client

//Enemy Vars including the enemy loop
const DWORD EntityPlayer_Base = 0x54D324;
//How far in memory is each enemy data
const DWORD EntityLoopDistance = 0x10;

//ViewAngles
//We find these by moving our mouse around constantly looking for changed/unchanged value,
//the alternative is to use cl_pdump 1 and search for the value assigned to m_angRotation vector
const DWORD dw_m_angRotation = 0x461A9C;



//We will use this struct throughout all other tutorials adding more variables every time
struct MyPlayer_t  
{ 
	DWORD CLocalPlayer; 
	int Team; 
	int Health; 
	float Position[3]; 
	void ReadInformation() 
	{
		// Reading CLocalPlayer Pointer to our "CLocalPlayer" DWORD. 
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + Player_Base), &CLocalPlayer, sizeof(DWORD), 0);
		// Reading out our Team to our "Team" Varible. 
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(CLocalPlayer + dw_mTeamOffset), &Team, sizeof(int), 0);
		// Reading out our Health to our "Health" Varible.     
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(CLocalPlayer + dw_Health), &Health, sizeof(int), 0); 
		// Reading out our Position to our "Position" Varible. 
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(CLocalPlayer + dw_Pos), &Position, sizeof(float[3]), 0); 

		//Here we find how many player entities exist in our game, through this we make sure to only loop the amount of times we need
		//when grabbing player data
		//Note that this call could be even better at a regular 15 or so seconds timer but performance shouldn't vary a great deal
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordEngine + dw_PlayerCountOffs), &NumOfPlayers, sizeof(int), 0); 
	}
}MyPlayer;    




//Here is where we narrow the enemy data to the enemies that we want to shoot, 
//these players are added once we validated them e.g. do they have enough health?, or maybe they are on the enemy team
struct TargetList_t 
{
	float Distance;
	float AimbotAngle[3];

	TargetList_t()
	{
		//our default constructor :S
	}

	TargetList_t(float aimbotAngle[], float myCoords[], float enemyCoords[])
	{
		//Send our coordinates and the enemy's to find out how close they are to us!
		Distance = Get3dDistance(myCoords[0], myCoords[1], myCoords[2],
								enemyCoords[0], enemyCoords[1], enemyCoords[2] );

		//Define our aimbot angles and set them for later use when shooting
		AimbotAngle[0] = aimbotAngle[0];
		AimbotAngle[1] = aimbotAngle[1];
		AimbotAngle[2] = aimbotAngle[2];
	}

	//Get our 3d Distance between 2 sets of coordinates(ours and enemies) and find out how close an enemy is to us
	//when it comes to shooting we aim at the closest enemy
	//Simple but effective

	//Here we will AVOID vectors for simplicity but feel free to create to use them
	//if you prefer float Get3dDistance(std::vector<float> myCoords, std::vector<float> enemyCoords)
	
	//See how far away our enemy is to us
	float Get3dDistance(float myCoordsX, float myCoordsZ, float myCoordsY, 
						float eNx, float eNz, float eNy)
	{
		//Use the 3d distance formula to get a resulting Floating distance value POW!!
		return sqrt(
			pow(double(eNx - myCoordsX), 2.0) + 
			pow(double(eNy - myCoordsY), 2.0) + 
			pow(double(eNz - myCoordsZ), 2.0));
	}
};



//ENemy struct
struct PlayerList_t 
{
	DWORD CBaseEntity; 
	int Team; 
	int Health; 
	float Position[3]; 
	float AimbotAngle[3]; 
	char Name[39]; 

	void ReadInformation(int Player) 
	{
		// Reading CBaseEntity Pointer to our "CBaseEntity" DWORD + Current Player in the loop. 0x10 is the CBaseEntity List Size 
		//"client.dll"+00545204 //0x571A5204
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + EntityPlayer_Base  + (Player * EntityLoopDistance)),&CBaseEntity, sizeof(DWORD), 0);
		// Reading out our Team to our "Team" Varible. 
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dw_mTeamOffset), &Team, sizeof(int), 0);
		// Reading out our Health to our "Health" Varible.     
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dw_Health), &Health, sizeof(int), 0); 
		// Reading out our Position to our "Position" Varible. 
		ReadProcessMemory (fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dw_Pos), &Position, sizeof(float[3]), 0); 
 	}
}PlayerList[32];  



//Used to compare the distance when sorting the array of Target Enemies
//JUST think of this as an assist for a sorting algorithm
//and this isn't necessarily related to hacking but it helps us out
struct CompareTargetEnArray
{
	//USE A COMPARATOR TO SORT OUR ARRAY nicely
	bool operator() (TargetList_t & lhs, TargetList_t & rhs) 
	{
		return lhs.Distance < rhs.Distance; 
	}
};


//Props to Nubtik and a couple of other places on the interwebs for this function
void CalcAngle( float *src, float *dst, float *angles )
{
	double delta[3] = { (src[0]-dst[0]), (src[1]-dst[1]), (src[2]-dst[2]) };
	double hyp = sqrt(delta[0]*delta[0] + delta[1]*delta[1]);
	angles[0] = (float) (asinf(delta[2]/hyp) * 57.295779513082f);
	angles[1] = (float) (atanf(delta[1]/delta[0]) * 57.295779513082f);
	angles[2] = 0.0f;

	if(delta[0] >= 0.0) 
	{ 
		angles[1] += 180.0f; 
	}
}






void Aimbot()
{
	//Declare our target list to define our victims through a dynamic array
	TargetList_t* TargetList = new TargetList_t[NumOfPlayers];
	//Loop through all our players and retrieve their information
	//we use this mainly here to find out what players are our enemies and what players are on our team
	//loops through players to set the target enemies
	int targetLoop = 0;
	for(int i = 0; i < NumOfPlayers; i ++)
	{
		PlayerList[i].ReadInformation(i);

		// Skip if they're my teammates. 
		if (PlayerList[i].Team == MyPlayer.Team) 
			continue; 

		//Make sure our targets have at keast 2 health
		if (PlayerList[i].Health < 2) 
			continue; //break to next iteration

		//PlayerList[i].Position[2] -= 10;
		CalcAngle (MyPlayer.Position, PlayerList[i].Position, PlayerList[i].AimbotAngle);  

		//ONCE WE GET HERE we have already read all the information we want, all enemies have been checked for valid data
		//Therefore players on our team a dont get selected and only enemies with over 1 health are allowed

		//WE NOW DEFINE A LIST OF ENEMIES TO SHOOT AT, from here we will scan that array and choose to aim at the closest one
		//Create our target loop player and store the most important information
		TargetList[targetLoop] = TargetList_t(PlayerList[i].AimbotAngle, MyPlayer.Position, PlayerList[i].Position);

		//Increment so we can add more players onto the array
		targetLoop++;
	}




	//ONLY AIM if we have any enemies 
	if(targetLoop > 0)
	{
		//SORT ENEMIES ARRAY BY DISTANCE before AIMING AT THEM
		//JUST NORMAL std::sort function with our custom comparator, not much to it
		//target loop -1 because it will always go 1 above the count
		std::sort(TargetList, TargetList+targetLoop, CompareTargetEnArray());

		//AIM at the closest guy we found, 
		//by default aim at ALL times, if you right click hold it switches it off
		//This isn't the best example but change the example to whatevery you like E.g. Left click etc...
		if (!GetAsyncKeyState(0x2)) 
		{

			WriteProcessMemory (fProcess.__HandleProcess, 
				(PBYTE*)(fProcess.__dwordEngine + dw_m_angRotation), 
					TargetList[0].AimbotAngle, 12, 0); 	

			//no recoil above text
		}

	}
	//reset the loop counter
	targetLoop = 0;
	//DELETE OUR ARRAY and clear memory, very important
	delete [] TargetList;
}



int main()
{
	fProcess.RunProcess(); // Waiting for CSS......
	cout << "Game found! Running Aimbot..." << endl; 

	//Exit if the F6 key is pressed
	while (!GetAsyncKeyState(F6_Key)) // or for(;;)
	{
		//Read player information into our struct so we know the player 
		//base and the bunny hop addresses
		MyPlayer.ReadInformation(); 

		//Call our Aimbot
		Aimbot();
	}
}