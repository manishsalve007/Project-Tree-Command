Title : tree Command

Project Description:
	
tree command displays each directory name along with the names of any subdirectories within it. The display will be in a format like the summary below.
I have implemented the following [options] in tree command, and their functions are given below.

-a  :-		All files are printed.By default tree does not print hidden files(those begin with 			dot "."). In no event does the tree print the file system constructs '.' (current 			directory) and '..' (previous directory).

-d  :-		List directories only.

-f  :-          Prints the full path prefix for each file.

-i :-		Makes tree not print the indentation lines, useful when used in
                conjunction with the -f option.
                
and commands with multiple options:
                
[-a -d] , [-a -d -f]  , [-a -d -f -i]
