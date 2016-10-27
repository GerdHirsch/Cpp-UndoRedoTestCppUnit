/*
 * UndoRedoStackTest.cpp
 *
 *  Created on: 27.10.2016
 *      Author: Gerd
 */

#include "../include/UndoRedoStackTest.h"

#include <iostream>
#include <exception>
using namespace std;

//void _UndoRedoStackTest::testDoIt(){
//	char const* message = "DemoTest";
//	CPPUNIT_ASSERT_EQUAL_MESSAGE(message, 0, -1);
//}

void UndoRedoStackTest::testDoIt(){
	Plus::throwException() = false;
	int result = calculator.getResult();
	int expected = 0;
	CPPUNIT_ASSERT_EQUAL(expected, result);
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isRedoable());

	urMngr.doIt(plus);

	expected = plusValue;
	result = calculator.getResult();
	CPPUNIT_ASSERT_EQUAL(expected, result);

	CPPUNIT_ASSERT_EQUAL(true, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isRedoable());
}
void UndoRedoStackTest::testDoItWithException(){
	Plus::throwException() = true;
	int result = calculator.getResult();
	int expected = 0;
	CPPUNIT_ASSERT_EQUAL(expected, result);

	try{
		urMngr.doIt(plus);
	}catch(std::exception& e){}

	CPPUNIT_ASSERT_EQUAL(expected, result);
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isRedoable());

}

void UndoRedoStackTest::testDoItExceptionNeutral(){
	Plus::throwException() = true;

	CPPUNIT_ASSERT_THROW(urMngr.doIt(plus), std::logic_error);

}
//==========
void UndoRedoStackTest::testUndo(){
	Plus::throwException() = false;
	urMngr.doIt(plus);
	urMngr.undo();

	int result = calculator.getResult();
	int expected = 0;

	CPPUNIT_ASSERT_EQUAL(expected, result);

	CPPUNIT_ASSERT_EQUAL(false, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isRedoable());
}
void UndoRedoStackTest::testUndoWithException(){
	urMngr.doIt(plus);
	Plus::throwException() = true;
	try{
		urMngr.undo();
	}catch(std::exception& e){
		cout << "catch testUndoWithException" << endl;
	}

	int result = calculator.getResult();
	int expected = plusValue;

	CPPUNIT_ASSERT_EQUAL(expected, result);
	CPPUNIT_ASSERT_EQUAL(true, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isRedoable());
}

void UndoRedoStackTest::testUndoExceptionNeutral(){
	Plus::throwException() = false;
	urMngr.doIt(plus);
	Plus::throwException() = true;

	CPPUNIT_ASSERT_THROW(urMngr.undo(), std::logic_error);
}
//==========
void UndoRedoStackTest::testRedo(){
	Plus::throwException() = false;
	urMngr.doIt(plus);
	urMngr.undo();

	int result = calculator.getResult();
	int expected = plusValue;

	CPPUNIT_ASSERT_EQUAL(false, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(true, urMngr.isRedoable());

	CPPUNIT_ASSERT_EQUAL(expected, result);

	urMngr.redo();

	result = calculator.getResult();
	expected = 0;

	CPPUNIT_ASSERT_EQUAL(expected, result);

	CPPUNIT_ASSERT_EQUAL(true, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(false, urMngr.isRedoable());
}
void UndoRedoStackTest::testRedoWithException(){
	Plus::throwException() = false;
	urMngr.doIt(plus);
	urMngr.undo();
	Plus::throwException() = true;
	try{
		urMngr.redo();
	}catch(std::exception& e){
		cout << "catch testUndoWithException" << endl;
	}

	int result = calculator.getResult();
	int expected = 0;

	CPPUNIT_ASSERT_EQUAL(expected, result);

	CPPUNIT_ASSERT_EQUAL(false, urMngr.isUndoable());
	CPPUNIT_ASSERT_EQUAL(true, urMngr.isRedoable());
}

void UndoRedoStackTest::testRedoExceptionNeutral(){
	Plus::throwException() = false;
	urMngr.doIt(plus);
	urMngr.undo();
	Plus::throwException() = true;

	CPPUNIT_ASSERT_THROW(urMngr.redo(), std::logic_error);
}
