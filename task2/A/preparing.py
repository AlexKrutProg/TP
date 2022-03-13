import sys
file_name = sys.argv[1]
file = open(file_name, "w+")
file.write("class Array {" + "\n")
file.write("    long long* arr;" + "\n")
file.write("public:" + "\n")
file.write("    size_t sz;" + "\n")           
file.write("    Array(size_t sz);" + "\n")
file.write("    ~Array();" + "\n")
file.write("    long long& operator[](size_t index);" + "\n")
file.write("};" + "\n")
file.close()
