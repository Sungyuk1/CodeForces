#include <iostream>
#include <unordered_set>
using namespace std;

/*
Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones.
Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

Help Petya cope with this easy task.

Input
The first line represents input string of Petya's program. This string only consists of uppercase and lowercase Latin letters and its length is from 1 to 100, inclusive.

Output
Print the resulting string. It is guaranteed that this string is not empty.

*/
int main()
{
    string input;
    cin>>input;

    string output = "";
    unordered_set<char> vowelSet;
    vowelSet.insert('a');
    vowelSet.insert('o');
    vowelSet.insert('y');
    vowelSet.insert('e');
    vowelSet.insert('u');
    vowelSet.insert('i');
    vowelSet.insert('A');
    vowelSet.insert('O');
    vowelSet.insert('Y');
    vowelSet.insert('E');
    vowelSet.insert('U');
    vowelSet.insert('I');


    for( int i = 0; i<input.size(); ++i){
        if(vowelSet.find(input[i]) == vowelSet.end()){
            output+='.';
            output+=(char)tolower(input[i]);
        }

    }
    cout<<output<<endl;
}