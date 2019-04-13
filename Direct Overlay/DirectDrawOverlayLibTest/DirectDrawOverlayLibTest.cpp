#define BOOST_AUTO_TEST_MAIN
#include <boost\test\auto_unit_test.hpp>
#include <OverlayRectangle.h>
#include <Exception.h>

DDCAPS MakeCaps(DWORD flags = 0,
				DWORD alignBoundarySrc = 0,
				DWORD alignBoundaryDest = 0,
				DWORD alignSizeSrc = 0,
				DWORD alignSizeDest = 0,
				DWORD minStretch = 0,
				DWORD maxStretch = 0)
{
	DDCAPS caps;
	memset(&caps, 0, sizeof(DDCAPS));

	caps.dwSize = sizeof(DDCAPS);
	caps.dwCaps = flags;
	caps.dwAlignBoundarySrc = alignBoundarySrc;
	caps.dwAlignBoundaryDest = alignBoundaryDest;
	caps.dwAlignSizeSrc = alignSizeSrc;
	caps.dwAlignSizeDest = alignSizeDest;
	caps.dwMinOverlayStretch = minStretch;
	caps.dwMaxOverlayStretch = maxStretch;

	return caps;
}

BOOST_AUTO_TEST_CASE(TestRectangleNoRestrictions)
{
	const DDCAPS noRestrictionCaps = MakeCaps();
	const Overlay::Rectangle rs = Overlay::CreateSourceRectangle(noRestrictionCaps, 
		123, 456, 321, 654);
	BOOST_CHECK(
		rs.Left() == 123 &&
		rs.Top() == 456 && 
		rs.Width() == 321 && 
		rs.Height() == 654);

	const Overlay::Rectangle rd = Overlay::CreateDestinationRectangle(noRestrictionCaps, 
		rs, 123, 456, 321, 654);
	BOOST_CHECK(
		rd.Left() == 123 && 
		rd.Top() == 456 && 
		rd.Width() == 321 && 
		rd.Height() == 654);
}

BOOST_AUTO_TEST_CASE(TestRectangleBoundary)
{
	const DDCAPS srcBoundaryCaps = MakeCaps(DDCAPS_ALIGNBOUNDARYSRC, 123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateSourceRectangle(srcBoundaryCaps, 123, 10, 10, 10).Left(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateSourceRectangle(srcBoundaryCaps, 10, 10, 10, 10).Left(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateSourceRectangle(srcBoundaryCaps, 125, 10, 10, 10).Left(),
		246);	

	const DDCAPS destBoundaryCaps = MakeCaps(DDCAPS_ALIGNBOUNDARYDEST, 0, 123);
	const Overlay::Rectangle rs = Overlay::CreateSourceRectangle(destBoundaryCaps, 
		123, 456, 321, 654);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(destBoundaryCaps, rs, 123, 10, 10, 10).Left(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(destBoundaryCaps, rs, 10, 10, 10, 10).Left(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(destBoundaryCaps, rs, 125, 10, 10, 10).Left(),
		246);
}

BOOST_AUTO_TEST_CASE(TestRectangleSize)
{
	const DDCAPS srcSizeCaps = MakeCaps(DDCAPS_ALIGNSIZESRC, 0, 0, 123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateSourceRectangle(srcSizeCaps, 0, 10, 10, 10).Width(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateSourceRectangle(srcSizeCaps, 10, 10, 123, 10).Width(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateSourceRectangle(srcSizeCaps, 0, 10, 124, 10).Width(),
		246);

	const DDCAPS destSizeCaps = MakeCaps(DDCAPS_ALIGNSIZEDEST, 0, 0, 0, 123);
	const Overlay::Rectangle rs = Overlay::CreateSourceRectangle(destSizeCaps, 
		123, 456, 321, 654);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(destSizeCaps,  rs, 0, 10, 10, 10).Width(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(destSizeCaps, rs, 0, 10, 123, 10).Width(),
		123);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(destSizeCaps, rs, 0, 10, 124, 10).Width(),
		246);
}

BOOST_AUTO_TEST_CASE(TestRectangleStretch)
{
	// No stretching allowed
	const DDCAPS noStretchCaps = MakeCaps(DDCAPS_OVERLAYSTRETCH, 0, 0, 0, 0,
		1000, 1000);
	const Overlay::Rectangle rs = Overlay::CreateSourceRectangle(noStretchCaps, 
		1, 2, 3, 4);
	const Overlay::Rectangle rd = Overlay::CreateDestinationRectangle(noStretchCaps, rs,
		0, 0, 320, 240);
	BOOST_CHECK(
		rd.Width() == 3 &&
		rd.Height() == 240);

	// Stretching allowed with min = 0.5 and max = 2
	const DDCAPS stretchCaps = MakeCaps(DDCAPS_OVERLAYSTRETCH, 0, 0, 0, 0,
		500, 2000);
	const Overlay::Rectangle rs2 = Overlay::CreateSourceRectangle(stretchCaps, 
		1, 2, 300, 4);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(stretchCaps, rs2, 0, 0, 150, 240).Width(),
		150);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(stretchCaps, rs2, 0, 0, 300, 240).Width(),
		300);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(stretchCaps, rs2, 0, 0, 600, 240).Width(),
		600);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(stretchCaps, rs2, 0, 0, 149, 240).Width(),
		150);
	BOOST_CHECK_EQUAL(
		Overlay::CreateDestinationRectangle(stretchCaps, rs2, 0, 0, 601, 240).Width(),
		600);	
}