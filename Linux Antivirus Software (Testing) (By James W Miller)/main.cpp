#include <cstdio>
#include<string>
int cfViruses()
{
    printf("Checking File access and restrictions...");
    checkfiles();
        //if ();
    return 0;
}
int checkfiles()
{
    // This is borrowed code to be used for searching files 
    bool find_file(const path & dir_path,         // in this directory,
        const std::string & file_name, // search for this name,
        path & path_found)            // placing path here if found
    {
        if (!exists(dir_path)) return false;
        directory_iterator end_itr; // default construction yields past-the-end
        for (directory_iterator itr(dir_path);
            itr != end_itr;
            ++itr)
        {
            if (is_directory(itr->status()))
            {
                if (find_file(itr->path(), file_name, path_found)) return true;
            }
            else if (itr->leaf() == file_name) // see below
            {
                path_found = itr->path();
                return true;
            }
        }
        return false;
    }
}
int main()
{
    printf("Hello There!");
    return 0;
    cfViruses();
}
