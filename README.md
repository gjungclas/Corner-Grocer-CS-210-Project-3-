# The Corner Grocer (C++)
# Project Summary:
The Corner Grocer application is a C++ tool designed to analyze daily purchase records for a local grocery store. The program solves the problem of high-volume data interpretation by reading an unstructured text file of items sold, calculating the frequency of each item, and presenting the data in three formats: a specific item search, a full frequency list, and a visual text-based histogram. Additionally, the program ensures data persistence by automatically generating a backup file (frequency.dat) for future processing.

# Portfolio Reflection: 
  What I Did Well: 
    I am particularly proud of the structural integrity of this project. By implementing a three-tier architecture—separating the program into Data (File), Logic (GroceryItem), and Presentation (Display) classes—I created a     professional-grade application that avoids the clutter of a monolithic main.cpp. This modularity ensures that the code is easy to debug and test.
  
  Enhancements and Efficiency: 
    While the current version uses a std::map for efficient O(log n) lookups, I could enhance the code by implementing a graphical user interface (GUI) or a web-based dashboard using a C++ framework like Wt. This would          move the program beyond the console, making it more accessible to non-technical store managers. From a security perspective, adding file encryption to the frequency.dat backup would better protect the store’s internal       sales data.
  
  Challenges and Problem-Solving:
    The most challenging aspect was managing the C++ input buffer and the logic for the initial file read. Initially, I encountered a "double-read" bug where the program would attempt to process data twice. I overcame this      by mastering the cin.clear() and cin.ignore() functions and refining the loop logic to check the stream state correctly. Throughout this process, I added technical documentation, developer communities, and iterative         testing to my support network, learning that a clinical step-by-step trace of the logic is the most effective way to solve complex bugs.
  
  Transferable Skills:
    The most transferable skill from this project is the mastery of Object-Oriented Programming (OOP) principles, specifically encapsulation and the use of the C++ Standard Template Library (STL). The ability to choose the      correct data structure—in this case, a std::map to handle unique keys and associated values—is a fundamental skill that applies to database management, cybersecurity, and software development.
  
  Maintainability, Readability, and Adaptability: 
    To ensure this program is maintainable and readable, I adhered to strict documentation standards, including header guards (#ifndef), consistent naming conventions, and detailed in-line comments. The code is adaptable        because of its modular design; for example, the Display class could be completely replaced with a different interface without ever needing to change the core logic in the GroceryItem or File classes. This "pluggable"        nature is a hallmark of industry-standard software engineering.
