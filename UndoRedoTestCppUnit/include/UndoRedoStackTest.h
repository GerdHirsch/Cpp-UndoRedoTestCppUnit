/*
 * UndoRedoStackTest.h
 *
 *  Created on: 27.10.2016
 *      Author: Gerd
 */

#ifndef UNDOREDOSTACKTEST_H_
#define UNDOREDOSTACKTEST_H_

#include "../include/UndoRedoTest.h"
#include "../include/Test.h"

class UndoRedoStackTest : public UndoRedoTest {
	CPPUNIT_TEST_SUITE(UndoRedoStackTest);

	CPPUNIT_TEST(testDoIt);
	CPPUNIT_TEST(testDoItWithException);
	CPPUNIT_TEST(testDoItExceptionNeutral);
	CPPUNIT_TEST(testUndo);
	CPPUNIT_TEST(testUndoWithException);
	CPPUNIT_TEST(testUndoExceptionNeutral);

	CPPUNIT_TEST_SUITE_END();
public:

protected:

	void testDoIt();
	void testDoItWithException();
	void testDoItExceptionNeutral();

	void testUndo();
	void testUndoWithException();
	void testUndoExceptionNeutral();
	void testRedo();
	void testRedoWithException();
	void testRedoExceptionNeutral();
};

#endif /* UNDOREDOSTACKTEST_H_ */
