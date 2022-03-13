import sys
file_name = sys.argv[1]
file = open(file_name, "w+")
file.write("size_t sz = 5;" + "\n")
file.write("int arr[] = {1, 2, 3, 4, 5};")
file.close()
