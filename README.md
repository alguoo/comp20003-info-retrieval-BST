# Information Retrieval via BST
Objective is to use BST as a data structure to store and retrieve information, in this case, Olympics athletes across the years.

# Implementations
From scratch, the following was created/implemented:
1. BST structure
   * Data insertion
   * Tree freeing
2. CSV reader/printer
3. Optimisation: Dynamically allocated memory for arbitrarily long strings
4. BST Dictionary
   * Searching for data, outputting duplicated results

# Experimentation
Two of the operations of the BST dictionary explored in this assignment is the insertion and search time complexity. Two factors which can impact this is:
1.	The order in which the data is inserted
    * Grouped
    * Randomly
    * Sorted
2.	The method of handling insertions of duplicate keys
    * Always placed as left child (dict1)
    * Points to a linked list of duplicates (dict2)

See report for the analysis.




