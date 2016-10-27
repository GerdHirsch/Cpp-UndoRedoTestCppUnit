/*
 * UndoRedoTest.h
 *
 *  Created on: 27.10.2016
 *      Author: Gerd
 */

#ifndef INCLUDE_UNDOREDOTEST_H_
#define INCLUDE_UNDOREDOTEST_H_

#include "../include/Test.h"

class UndoRedoTest : public CPPUNIT_NS::TestFixture {
protected:
	Calculator calculator;
	int plusValue;
	int minusValue;
	Plus plus;
	Minus minus;
	UndoRedoManagerImpl undoRedoManager;
	UndoRedoManager& urMngr;
public:
	UndoRedoTest() :
		calculator(),
		plusValue(3),
		minusValue(1),
		plus(calculator, plusValue),
		minus(calculator, minusValue),
		urMngr(undoRedoManager)
	{
		Plus::throwException() = false;

	}

};



#endif /* INCLUDE_UNDOREDOTEST_H_ */
