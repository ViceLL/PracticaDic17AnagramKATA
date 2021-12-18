#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include "../C++AnagramKATA/C++AnagramKATA.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAnagramKATA
{
	TEST_CLASS(UnitTestAnagramKATA)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			//Arrange;	
			vector<string> words =
			{
				"kinship","pinkish"
			};									

			//Act
			set<set<string>> anagrams = groupAnagrams(words);
			

			//Assert
			Assert::AreEqual("pinkish", "pinkish");


		}
	};
}
