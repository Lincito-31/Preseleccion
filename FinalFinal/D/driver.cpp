// You don't have to look at this file, it contains some filesystem interaction so that you
// don't have to worry about processing all the files you need.
//
// Simply compile `translation.cpp` and run the resulting binary without arguments to see
// the usage instructions.

/////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

string classify(const string&);
const string VALID_LANGUAGES[] = {"en", "eo", "id", "mi", "jbo"};

void usage(const string& self) {
    cerr
        << "Run this as `" << self << " <name>`, where <name> is a file or a directory.\n"
        << " For instance, running `" << self
        << " reference/en_1.txt` will run your function that file and print out the result.\n"
        << " and running `" << self
        << " set_A` will run your function on all the files for subtask A and output the results "
           "in the correct order.\n\n"
        << "You can save the result into a file by redirecting stdout, like with `" << self
        << " set_A > output_A.txt`.\n\n"
        << "This program will output a warning to stderr (and hence not to the file you can "
           "submit) when your function outputs something that is not recognized as a language code."
        << endl;
}

bool isfile(const string& name) {
    struct stat st;
    if (stat(name.c_str(), &st)) {
        if (errno == ENOENT)
            return false;
        perror("stat");
        exit(1);
    }
    return S_ISREG(st.st_mode);
}

bool isdir(const string& name) {
    struct stat st;
    if (stat(name.c_str(), &st)) {
        if (errno == ENOENT)
            return false;
        perror("stat");
        exit(1);
    }
    return S_ISDIR(st.st_mode);
}

void run_file(const string& name) {
    ifstream inf{name};
    string content{istreambuf_iterator<char>(inf), istreambuf_iterator<char>()};
    string result = classify(content);
    if (find(begin(VALID_LANGUAGES), end(VALID_LANGUAGES), result) == end(VALID_LANGUAGES)) {
        cerr << "WARNING: classify resulted in an unknown language: " << result
             << " (file: " << name << ")" << endl;
    }
    cout << result << endl;
}

vector<string> listdir(const string& name) {
    vector<string> res;
    DIR* dir = opendir(name.c_str());
    if (!dir) {
        perror("opendir");
        return res;
    }
    while (struct dirent* ent = readdir(dir)) {
        if (ent->d_name[0] != '.')
            res.emplace_back(ent->d_name);
    }
    closedir(dir);
    return res;
}

int filename_num(const string& f) {
    string::size_type idx = f.find('.');
    if (idx == f.npos)
        return INT_MAX;
    string name = string{f.begin(), f.begin() + idx};
    size_t nread;
    if (all_of(name.begin(), name.end(), ::isdigit)) {
        int res = stoi(name, &nread);
        if (nread == name.size())
            return res;
    }
    return INT_MAX;
}

bool filename_comparator(const string& a, const string& b) {
    return make_pair(filename_num(a), a) < make_pair(filename_num(b), b);
}

void run_dir(const string& name) {
    vector<string> filenames = listdir(name);
    sort(filenames.begin(), filenames.end(), filename_comparator);
    for (const auto& fname : filenames) {
        string path = name + "/" + fname;
        if (isfile(path)) {
            run_file(path);
        } else if (isdir(path)) {
            run_dir(path);
        } else {
            cerr << path << " is neither file nor directory, ignoring." << endl;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        usage(argv[0]);
        return 0;
    }

    string name = argv[1];
    if (isfile(name)) {
        run_file(name);
    } else if (isdir(name)) {
        run_dir(name);
    } else {
        cerr << name << " is neither a file nor a directory!\n" << endl;
        usage(argv[0]);
        return 1;
    }
}
