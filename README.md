This repository contains the source code for an interactive cricket game developed in C language. The game features a match between the computer and the user, employing various data structures such as linked lists, stacks, and queues to manage game data efficiently.

Key Features:

Toss Simulation: The game uses the rand function to simulate a toss, determining whether the user or the computer bats or bowls first.
Score Management: Scores for the player currently batting are stored in a linked list for dynamic and efficient data management.
User Input Handling: As the second player bats, their inputs are recorded in a linked list, ensuring consistent and seamless gameplay.
Match History Storage: The game maintains a history of the last 5 matches using a stack, allowing quick retrieval of recent game results.
Technical Details:

Language: C
Data Structures Used: Linked List, Stack, Queue
Execution: Runs on a terminal, with no graphical user interface (GUI).
How to Run:

Clone the repository.
Compile the source code using a C compiler (e.g., gcc cricket_game.c -o cricket_game).
Run the executable (e.g., ./cricket_game).
Purpose:
This project aims to demonstrate the use of fundamental data structures in game development, focusing on logical implementation and efficient data management.

Future Improvements:

Adding a graphical user interface (GUI) for better user experience.
Implementing additional features like player statistics and detailed match analysis.
