#include "Map.h"
#include "Global.h"
using namespace System;
using namespace ZS;

[STAThread]
int StartMap()  
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Map);
	return 0;
}

bool __stdcall CharDetection()
{
	for(;;)
	{
		if (MapID > 0) // Only if Logged on
		{
			/*Get Location of the X,Y on Mini Map*/
			double MiniX = (double) (WallLeftRatio + (CharX * XRatio));
			double MiniY = (double) ((WallBottomRatio  - (10 * YRatio)) + (CharY * YRatio));

			/*Set Mini Map X,Y*/
			Map::MiniMap->Character->Location = Point(MiniX, MiniY);
			//Map::MiniMap->label1->Text = WallBottom.ToString();
			//Map::MiniMap->label2->Text = CharY.ToString();

			/*::MessageBox(0, sToLPCSTR(
				"X,Y: " + CharX.ToString() + " , " + CharY.ToString() + "\n" +
				"Map Size: " + MapX.ToString() + " , " + MapY.ToString() + "\n" +
				"Mini Map Size: " + Map::MiniMap->Picture->Height + " , " + Map::MiniMap->Picture->Width + "\n" +
				"Left Wall: " + WallLeft.ToString() + "\n" +
				"Bottom Wall: " + WallBottom.ToString() + "\n" +
				"Top Wall: " + WallTop.ToString() + "\n" + 
				"Right Wall: " + WallRight.ToString() + "\n" +
				"Wall Ratio: " + WallLeftRatio.ToString() + " , " + WallTopRatio.ToString() + "\n" +
				"Center XY: " + CenterX + " , " + CenterY + "\n" +
				"XY Ratio: " + XRatio.ToString() + " , " + YRatio.ToString() + "\n" +
				"Char Mini X,Y: " + CharMiniX.ToString() + " , " + CharMiniY.ToString() + "\n" +
				"Mini X,Y: " + MiniX.ToString() + " , " + MiniY.ToString()
				), Title, MB_OK);*/
			
			
			
		}
		Sleep(250);
	}
}

bool __stdcall MapLoader()
{
	for(;;)
	{
		if (MapID > 0) // Only if Logged on
		{
			if (!MapVisible)
			{
				Map::MiniMap->Show();
				MapVisible = true;
			}

			if (CurMap != MapID)
			{
				/* Get Mini Map Image*/
				String^ MapId = MapID.ToString();
	
				System::Net::HttpWebRequest^ wReq = dynamic_cast<System::Net::HttpWebRequest^>(System::Net::WebRequest::Create("http://www.forgottenpassage.org/xmls/Map.wz/Map/Map"+MapId[0]+"/"+MapId+".img/miniMap/canvas.png"));
				System::Net::HttpWebResponse^ wRes = dynamic_cast<System::Net::HttpWebResponse^>(wReq->GetResponse());
	
				if (wRes->ResponseUri->ToString() != "http://www.forgottenpassage.org/images2/noicon.png")
				{
					MapImageFound = true;
					Map::MiniMap->Picture->Image = Image::FromStream(wRes->GetResponseStream());
					Map::MiniMap->Size = Size(Map::MiniMap->Picture->Width + 16, Map::MiniMap->Picture->Height + 34);
					XRatio = (double)Map::MiniMap->Picture->Width / MapX;
					YRatio = (double)Map::MiniMap->Picture->Height / MapY;
					WallLeftRatio = (double)(WallLeft * -1) * XRatio;
					WallBottomRatio =  (double)WallBottom * YRatio; 
				}
				else
				{
					MapImageFound = false;
					Map::MiniMap->Picture->Image = nullptr;
					Map::MiniMap->Size = Size(18, 36);
				}

				/*Get Current Mobs Choord*/

				CurMap = MapID;
			}
		}
		else
		{
			if (MapVisible)
			{
				MapVisible = false;
				Map::MiniMap->Hide();
			}
		}

	Sleep(250);
	}
}

void Map::Map_Load(System::Object^  sender, System::EventArgs^  e)
{
	MapVisible = true;
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MapLoader, 0, 0, NULL);
	//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CharDetection, 0, 0, NULL);
}

void Map::Map_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	e->Cancel = true;
}