#!/usr/bin/env ruby      
# Neh Patel 
# compile: chmod +x a5.rb 
# run: ./a5.rb

#READ FILE: just reads the file as a binary and returns it as one string
def read_file(file_name)
  # open file 
  puts "READING IN THE BINARY CORRECTLY!"
  file = File.open(file_name, "rb")
  data = file.read
  file.close
  return data
end

#READFILE: kind of an overload, attempt to convert form binary. 
#          Didn't really work out too well. So for partial credit
#          the function above this was added to show the file was read correctly
# CITATION: "What Are All the Common Ways to Read a File in Ruby?" 
#           - Stack Overflow. N.p., n.d. Web. 18 Nov. 2014.
#Site: http://stackoverflow.com/questions/5545068/what-are-all-the-common-ways
#      -to-read-a-file-in-ruby
def readfile(filename)
  puts "CONVERTING THE FILE, line by line"
  File.open(filename, 'rb') do |f|
  loop do
    break if not buf = f.gets(nil, 80)
    data = buf.unpack('H*')
    puts "\n"
    puts data
    end
  end
end

# MAIN: 
def main() 
  puts "Enter the name of file"
  # input 
  filename = gets.chomp  
  # print out the data read from the file
  puts read_file(filename)
  puts "\n\n"
  readfile(filename)
end

# need to call main or program wont run.
main()
