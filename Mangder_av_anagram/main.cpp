#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*  
 *  Hashes the input string into a hash that's unique for
 *  each word that contains the exact same letters.
 *  Accomplishes this by assigning a prime number to each
 *  letter and then multiplying the prime numbers with eachother,
 *  hence ab = ba, the resulting number will be unique for these
 *  letters because primes...
 *
 */
unsigned long int wordToHash(const string& word) {

    // Array containing the 29 first primes, one for each swedish letter.
    int primtal[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
        59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};


    unsigned long int hash = 1;

    // Multiply every letterPrimenumber with eachother
    // If the letter is latin(a-z) just decrease the
    // letter with 97(since a begins at index 97 ascii).
    // Special cases for swedish letters(å,ä,ö)
    for(auto c : word){
        if(97 <= c <= 122)
            hash *= primtal[c-97];
        else if(c == 132) // ä
            hash *= primtal[28];
        else if(c == 134) // å
            hash *= primtal[27];
        else if(c == 148) // ö
            hash *= primtal[29];
    }

    return hash;
}

int main(int argc, char *argv[]) {
    

    unordered_multimap<unsigned long int, string> anagrams;

    vector<string> wordlist = {"algoritm", "komplexitet", "rotad", "dator", "logaritm", "ordat"};

    for(const auto &word : wordlist)
        anagrams.insert({wordToHash(word),word});

    
    auto it = anagrams.begin();

    while(it!= anagrams.end()) {
        unsigned long int key = it->first;

        if(anagrams.count(key) > 1) {
            auto range = anagrams.equal_range(key);
            for(auto it = range.first; it != range.second; it++)
                cout << it->second << " ";
        } else
            cout << it->second;

        cout << "\n";
        it = anagrams.equal_range(key).second;
    }
}
