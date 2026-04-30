# 🎒 Knapsack Visualizer & Solver

An interactive web application that visualizes the **0/1 Knapsack Problem** using Dynamic Programming, complete with a C++ console implementation that compares **Fractional** vs **0/1** knapsack approaches.

## Features

### Web Visualizer (`index.html`)
- ✅ **Interactive UI** - Add/remove items dynamically
- ✅ **DP Table Visualization** - See the entire DP table as it's computed
- ✅ **Traceback Highlighting** - Visual path showing which items were selected
- ✅ **Real-time Results** - Displays max value, total weight, and selected items
- ✅ **Responsive Design** - Works on desktop and tablet devices

### C++ Console Solver (`knapsack_solver.cpp`)
- ✅ **0/1 Knapsack** - Dynamic programming approach
- ✅ **Fractional Knapsack** - Greedy algorithm with value/weight ratio
- ✅ **DP Table Print** - Displays the complete DP matrix
- ✅ **Item Selection Trace** - Shows which items were chosen
- ✅ **Input Validation** - Handles edge cases and invalid inputs

## What is the Knapsack Problem?

The knapsack problem is a classic optimization problem:

> Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

### Two Variations:

| Variation | Description | Best Method |
|-----------|-------------|-------------|
| **0/1 Knapsack** | Each item can be taken at most once (either 0 or 1) | Dynamic Programming O(n×W) |
| **Fractional Knapsack** | Items can be broken into fractions | Greedy O(n log n) |

## 🛠️ Installation & Usage

### Web Visualizer
1. Clone the repository:
```bash
git clone https://github.com/yourusername/Knapsack-Visualizer-and-Solver.git
cd Knapsack-Visualizer-and-Solver
Open index.html in your browser:

bash
# On macOS
open index.html

# On Linux
xdg-open index.html

# On Windows
start index.html
C++ Solver
Compile the C++ program:

bash
g++ -o knapsack knapsack_solver.cpp -std=c++17
Run the executable:

bash
# On Unix/macOS
./knapsack
```
# On Windows
knapsack.exe
How to Use
Web Interface
Set Capacity - Enter the knapsack's weight limit

Add Items - Click "+ Add Item" to add items with weight and value

Solve - Click "Solve ▶" to compute the optimal solution

Explore - View the DP table with color-coded cells:

🟣 Purple - Final answer cell

🟢 Green - Items taken during traceback

🟡 Yellow - Items skipped during traceback

### C++ Program
```
Enter number of items: 4
Enter values of 4 items:
Item 1: 10
Item 2: 40
Item 3: 30
Item 4: 50
Enter weights of 4 items:
Item 1: 5
Item 2: 4
Item 3: 6
Item 4: 3
Enter knapsack capacity: 10

--- Output ---
Fractional Knapsack (Greedy): 100.00
0/1 Knapsack (DP):           90
```
### Algorithm Complexity
Algorithm	Time Complexity	Space Complexity
0/1 Knapsack (DP)	O(n × W)	O(n × W)
Fractional Knapsack	O(n log n)	O(1)
Where n = number of items, W = knapsack capacity

### DP Table Explanation
The DP table is built bottom-up:

Rows (i): Items 0 to n

Columns (w): Capacities 0 to W

Cell dp[i][w] = Maximum value achievable with first i items and capacity w

Recurrence Relation:

text
dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w - weight[i]])
### Project Structure
text
```
Knapsack-Visualizer-and-Solver/
├── index.html              # Web visualizer
├── knapsack_solver.cpp     # C++ console implementation
├── README.md               # This file
└── LICENSE                 # MIT License
```
Color Legend
Color	Meaning
🟣 highlight	Final answer cell (dp[n][W])
🟢 chosen-cell	Item was taken in optimal solution
🟡 traceback	Item was skipped in optimal solution
### Technologies Used
Frontend: HTML5, CSS3, JavaScript (ES6)

Styling: Custom CSS with CSS Grid & Flexbox

Fonts: Google Fonts (JetBrains Mono, Syne)

Backend Logic: Pure JavaScript (no frameworks)

Console: C++17 with STL

## Example Walkthrough
### Problem Instance:
Capacity: 10

Items: (w=5, v=10), (w=4, v=40), (w=6, v=30), (w=3, v=50)

### Optimal Solution (0/1):
Take Item 2 (w=4, v=40)

Take Item 4 (w=3, v=50)

Take Item 1 (w=5, v=10)

Total Value: 90

### Greedy Solution (Fractional):
Sort by value/weight ratio

Take items in ratio order

Total Value: 100 (allows fractions)

### Contributing
Contributions are welcome! Here's how:

Fork the repository

Create a feature branch (git checkout -b feature/AmazingFeature)

Commit changes (git commit -m 'Add AmazingFeature')

Push to branch (git push origin feature/AmazingFeature)

Open a Pull Request
### Acknowledgments
Dynamic Programming concept by Richard Bellman

Knapsack problem from combinatorial optimization

Icons and design inspiration from modern UI trends
