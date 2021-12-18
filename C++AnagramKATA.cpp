// C++AnagramKATA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

set<set<string>> groupAnagrams(vector<string> const& words)
{

    set<set<string>> anagrams;

    // construct a vector from the given words with each word sorted
    vector<string> list(words);
    for (string& s : list) 
    {        // don't forget to put `&`
        sort(s.begin(), s.end());
    }
    // construct a map where the key is each sorted word,
    // and value is a list of indices where it is present
    unordered_map<string, vector<int>> map;
    for (int i = 0; i < words.size(); i++) 
    {
        map[list[i]].push_back(i);
    }
    // traverse the map and read indices for each sorted key.
    // The anagrams are present in the actual list at those indices
    for (auto itr : map)
    {
        set<string> anagram;
        for (int index : itr.second) {
            anagram.insert(words[index]);
        }
        if (anagram.size() > 1) {
            anagrams.insert(anagram);
        }
    }
    return anagrams;
}
int main()
{
    // vector of words
    vector<string> words =
    {
        "kinship", "enlist", "boaster", "fresher", "sinks", "knits", "rots",
        "pinkfish", "inlets", "boaters", "refresh", "skins", "stink", "sort",
        "listen", "borates", "silent"
    };

    // get set containing all the anagrams grouped together
    set<set<string>> anagrams = groupAnagrams(words);

    // print the result
    for (set<string> anagram : anagrams) 
    {
        for (string s : anagram) 
{
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}
