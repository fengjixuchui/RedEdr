//#include "pch.h"
#include "CppUnitTest.h"

#include "eventproducer.h"
#include "utils.h"
#include "json.hpp"
#include "logging.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{
	TEST_CLASS(EventProducerTest)
	{
	public:
        TEST_METHOD(ConvertWstringToString) {
            std::wstring input = L"Hello\\World";
            std::string reference = "Hello\\World";

			std::string result = wstring_to_utf8(input);
			Assert::AreEqual(reference.c_str(), result.c_str());
        }
        TEST_METHOD(ConvertWstringToString2) {
            std::wstring input = L"Hello\\\\World";
            std::string reference = "Hello\\\\World";

            std::string result = wstring_to_utf8(input);
            Assert::AreEqual(reference.c_str(), result.c_str());
        }
	};
}
