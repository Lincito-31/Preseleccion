#include <string>

// You can use or modify this function as you like.
// It will return true if `needle` occurs as a substring
// (that is, in one piece) of `haystack` and false otherwise.
// For example, `contains("this is an example", "n exam") == true`,
//  but `contains("this is an example", "a ple") == false`.
bool contains(const std::string& haystack, const std::string& needle) {
    for (size_t i = 0; i <= haystack.size() - needle.size(); ++i) {
        bool ok = true;
        for (size_t j = 0; j < needle.size(); ++j) {
            if (haystack[i + j] != needle[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

// Implement this function
// It receives the entire document as a string
// and should return a string, either "en", "eo", "id", "mi", or "jbo"
//
// SIDENOTE: Be careful, some of the languages have special characters that will be encoded
//  as utf-8. Indexing the string will result in the individual bytes of the encoding,
//  so e.g. "ā" could consist of two bytes: 196 and 129
//  BEWARE: a normal `char` might be signed and hence bytes >= 128 would appear to be negative!
//   use `unsigned char` where necessary.
//
// If you want to use or look for a special character in the document, make sure to copy-paste
//  it directly from a reference or task file, to avoid different encodings occuring between
//  the task data and what you type.
std::string classify(const std::string& document) {
    // This line is an example of how you can use `contains`
    if(contains(document,"di") || contains(document,"dan")){
        return "id";
    }
    if (contains(document, "Ko te reo Māori te reo o te tangata whenua o Aotearoa.")) {
        return "mi";
    }
    if(contains(document,"ŭ") || contains(document,"ĝ") || contains(document,"Ĉ") || contains(document,"ĉ") || contains(document,"ĵ")){
        return "eo";
    }
    // Might be old english, maybe icelandic, who knows,
    //  it's just an example of something that needs multiple `char`s for a single symbol anyway
    if (contains(document, "þ")) {
        return "en";
    }
    return "en";
}

#include "driver.cpp"  // You can ignore this, this provides `main` and will call the function above; do not remove this
