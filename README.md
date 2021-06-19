# csvutils
C++ program that reads,writes,modify csv files 
It returns values in double vector form which can be manipulated according to the need.
it can be used by making its instance as:
object1=csvutils;

Below are the available fuctions to do the tasks:

1.csvreader(filename)-> This fuction reads the csv file with the location filename and returns values as a double vector of string.It saves the data as well for further operations.

2.csvwrite(double_vector_to_be_written_to_file,name_of_file_to_be_saved_as,headers)-> As the name suggest it takes double vector of string as input and saves in csv format.Headers are the title to be assigned to the values like name,age,address etc.Header should be a vector of string.

3.extract_data(string header) -> This returns all the data within the provided header.Like extract_data("name") wil give all the data with the header name in the file.

4.sort(string header) -> As the name it sorts the data according to the provided header name.Like if user have to sort the data according to name he uses sort("name").

5.shuffle() -> This shuffles the given data and returns the shuffle data.Point to be noted is that it set the value of original data as shuffled data as well so as to prevent anything messy.

6.deleteline(int line) -> This returns the data removing the data in the provided line.It returns a double vector which can be send as a argument to csvwrite function to write it permanently to the file.

7.replaceline(int line,vector<string> value) -> It replaces the given line with the data provided. The provided data should be a string vector with required values.

8.appendline(int line,vector<string> value) -> It append a new set of data in the provided line number and returns the appended data as well.

This file can be included as header in any project by importing it as:
  import <csvutils.h> //if its in path
  or
  import "path to csvutils.h" //if its in particular location to be accesed
