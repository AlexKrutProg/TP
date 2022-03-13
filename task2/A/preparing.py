import sys
file_name = sys.argv[1]
file = open(file_name, "w+")
file.write("int arr[] = {1, 2, 3, 4, 5};")
file.close()
