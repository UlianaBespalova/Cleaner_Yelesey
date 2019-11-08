#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <iostream>
#include "cleaner.h"

class ClassInitTests : public CppUnit::TestCase {
public:

    static void Test_constructor_init() {
        Cleaner cleaner;
        time_t T = 0;
        CPPUNIT_ASSERT_EQUAL(T, cleaner.Get_time());

        std::string db_name = "database_name";
        CPPUNIT_ASSERT_EQUAL(db_name, cleaner.Get_database());
    }

    static void Test_set_time() {
        Cleaner cleaner;
        time_t T = 60;
        cleaner.Set_time(T);
        CPPUNIT_ASSERT_EQUAL(T, cleaner.Get_time());
    }

    static void Test_set_database() {
        Cleaner cleaner;
        std::string db_name = "Users";
        cleaner.Set_database(db_name);
        CPPUNIT_ASSERT_EQUAL(db_name, cleaner.Get_database());
    }

    CPPUNIT_TEST_SUITE(ClassInitTests);
    CPPUNIT_TEST (Test_constructor_init);
    CPPUNIT_TEST (Test_set_time);
    CPPUNIT_TEST (Test_set_database);
    CPPUNIT_TEST_SUITE_END();

};

class CleaningTests : public CppUnit::TestCase {
public:

    static void Test_cleaning() {
        Cleaner cleaner;
        cleaner.Clean();
        //get hash array
        //delete from Users
        //delete from Used
        //insert into Unused
        //CPPUNIT_ASSERT_MESSAGE();
    }

    CPPUNIT_TEST_SUITE(CleaningTests);
    CPPUNIT_TEST (Test_cleaning);
    CPPUNIT_TEST_SUITE_END();

};

class DaemonWorkTests : public CppUnit::TestCase {
public:

    //static void Test_cleaning() {}

    static void Test_sleep() {

        const time_t timeSleep = 5;
        Cleaner cleaner;
        cleaner.Set_time(timeSleep);

        time_t start = clock();
        cleaner.Sleep();
        time_t finish = clock();
        time_t time = (finish-start)/CLOCKS_PER_SEC;

        CPPUNIT_ASSERT_MESSAGE("Sleep time doesn't match the set time", time>timeSleep&&time<timeSleep*1.05);

    }

    CPPUNIT_TEST_SUITE(DaemonWorkTests);
    CPPUNIT_TEST (Test_sleep);
    CPPUNIT_TEST_SUITE_END();

};


CPPUNIT_TEST_SUITE_REGISTRATION(ClassInitTests);
CPPUNIT_TEST_SUITE_REGISTRATION(CleaningTests);
CPPUNIT_TEST_SUITE_REGISTRATION(DaemonWorkTests);

int main() {

    CppUnit::Test* test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextTestRunner runner;
    runner.addTest(test);
    runner.run();
    return 0;
}