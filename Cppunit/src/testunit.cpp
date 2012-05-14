/*
 * testunit.cpp
 *
 *  Created on: May 3, 2012
 *      Author: jyagati
 */

#include "testUnit.h"
#include "Dbconnect.h"


void testUnit :: DbcheckConnection(void)
{
	CPPUNIT_ASSERT((mDbObj->CheckConnect()));
}
/*void testUnit::DBUpdate()
{
	mt_query = "updtae employee set ename='rakesh' where eno =20";
	CPPUNIT_ASSERT(mDbObj->DbUpdate(mt_query));
}*/

void testUnit::setUp()
{
	mDbObj = new Dbconnect();
}

void testUnit::tearDown()
{
	delete mDbObj;

}
