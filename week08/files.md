# Files

### Reading and writing to a file:  *demo in `append_line.c`*



7. Write a C program, ```append_line.c```, which is given one command-line argument, the name of a file, and which reads a line from ```stdin``` and appends it to the specified file.

2. What does ```fopen``` do? What are its parameters? What is the return value?

   ```
   Whenever you have to read/write or create a file, use fopen. 
   1st arg: pathname
   2nd arg: mode = "a"
   Returns a file pointer or null on error
   ```

3. What are some circumstances when ```fopen``` returns null?

   ```
   - If file doesn't exist with "a" given as mode
   - You do not have access to the file
   - Invalid mode
   - Not enough space on the system
   ```

4. How do you print the specific reason that caused `fopen` to return `NULL`?  

   *demo in `append_line.c`*

8. Why should you not use ```fgets``` or `fputs` with binary data?

   ```
   With strings, null terminators are reserved for the end of the string. Binary data may naturally contain zero bytes, and thus cannot be treated as a normal string.
   ```





### File metadata

13. Consider the following (edited) output from the command `ls -l ~cs1521`:

    ```
    drwxr-x--- 11 z5420403 cs1521 4096 Aug 27 11:59 17s2.work
    drwxr-xr-x  2 cs1521 cs1521 4096 Aug 20 13:20 bin
    -rw-r-----  1 cs1521 cs1521   38 Jul 20 14:28 give.spec
    drwxr-xr-x  3 cs1521 cs1521 4096 Aug 20 13:20 lib
    drwxr-x--x  3 cs1521 cs1521 4096 Jul 20 10:58 public_html
    drwxr-xr-x 12 cs1521 cs1521 4096 Aug 13 17:31 spim
    drwxr-x---  2 cs1521 cs1521 4096 Sep  4 15:18 tmp
    lrwxrwxrwx  1 cs1521 cs1521   11 Jul 16 18:33 web -> public_html
    ```

    1. Who can access the `17s2.work` directory?

       ```
       z5420403 (me), cs1521 (group), others can not
       ```

    2. What operations can a typical user perform on the `public_html` directory?

       ```
       Only execute
       ```

    3. What is the file `web`?

       ```
       symbolic link which is a special type of file which stores the name of the file we're pointing to
       ```

    4. What is the difference between `stat("sym", &info)` and `lstat("web", &info)`?
       (where `info` is an object of type `(struct stat)`)

       ```
       Using stat, you'll get the metadata of append_line.c (what it points to)
       Using lstat, you'll get the metadata of the actual symbolic link file
       ```



15. Write a C program, `chmod_if_public_write.c`, which is given 1+ command-line arguments which are the pathnames of files or directories

    If the file or directory is publically-writeable, it should change it to be not publically-writeable, leaving other permissions unchanged.

    It also should print a line to stdout