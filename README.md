Philosophers Project

Welcome to the Philosophers project! This project explores the classic Dining Philosophers Problem as introduced by Edsger Dijkstra. The primary goal is to implement a solution that adheres to the principles of concurrency, synchronization, and resource management while preventing deadlocks and starvation.
🧠 Concept

The Dining Philosophers Problem involves N philosophers sitting around a circular table, alternating between eating and thinking. Between each pair of philosophers is a single fork. To eat, a philosopher needs to pick up both forks adjacent to them. This creates a challenge of managing shared resources (forks) without causing deadlocks.
🚀 Features

    Multithreading: Each philosopher runs as an independent thread, simulating concurrent behavior.
    Synchronization: Proper use of mutexes to avoid race conditions and ensure safe resource sharing.
    Simulation:
        Philosophers alternate between eating, thinking, and sleeping.
        A philosopher eats only when both forks are available.
    Resource Management:
        Prevents deadlock and starvation.
        Implements a solution for handling forks efficiently.
    Dynamic Configuration:
        Number of philosophers.
        Time to die, eat, and sleep.
        Number of meals (optional).
    Error Handling:
        Detects invalid input and configuration issues.
        Handles edge cases like single philosopher scenarios.
    Performance: Optimized for minimal delay and accurate timing.

🛠️ Technologies Used

    C Programming Language: For high-performance and low-level threading operations.
    POSIX Threads (pthreads): For managing concurrency.
    Mutexes: For thread synchronization.
    Makefile: For automated builds and dependency management.

📁 Project Structure

philosophers/
├── src/
│   # Entry point for the simulation
│   # Initialization of philosophers and resources
│   # Core logic for the philosophers' behavior
│   # Helper functions (e.g., time calculations, logging)
│   # Resource deallocation and cleanup
├── include/
│   ├── philo.h   # Main header file
└── Makefile             # Build automation

🔧 How to Build and Run

    Clone the repository:

git clone https://github.com/Sebrani-Aymane/ppphhhiiloo.git
cd philosophers

Build the project:

make

Run the program with configuration:

./philo[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals (optional)]

Example:

./philo 5 800 200 200

Clean the build:

    make clean

📋 Usage

    Parameters:
        number_of_philosophers: Number of philosophers sitting at the table.
        time_to_die: Maximum time (in ms) a philosopher can go without eating.
        time_to_eat: Time (in ms) a philosopher spends eating.
        time_to_sleep: Time (in ms) a philosopher spends sleeping.
        number_of_meals (optional): Number of times each philosopher must eat (simulation ends when all philosophers have eaten this many times).

    Behavior:
        Philosophers think, eat, and sleep in a loop.
        Logs provide real-time updates on the actions of each philosopher:

        [timestamp] Philosopher 1 is eating
        [timestamp] Philosopher 2 has taken a fork
        [timestamp] Philosopher 3 is thinking

🧪 Testing

    Run provided test scenarios:

    make test

    Customize test cases in the tests/ directory to simulate edge cases (e.g., single philosopher, minimal time_to_die).

🌟 Project Goals

    Learn the fundamentals of multithreading and synchronization.
    Develop an understanding of race conditions, deadlocks, and resource contention.
    Gain experience in designing efficient and safe concurrency algorithms.
    Showcase expertise in low-level programming with an emphasis on timing and performance.

🧵 Challenges Addressed

    Deadlock Prevention: Implements strategies to ensure philosophers do not wait indefinitely.
    Starvation Avoidance: Guarantees all philosophers get a chance to eat.
    Timing Accuracy: Maintains precision in millisecond-level timing of actions.

🤝 Contributing

Contributions are welcome! To contribute:

    Fork the repository.
    Create a feature branch:

git checkout -b feature-name

Commit your changes and push:

    git commit -m "Add feature description"
    git push origin feature-name

    Open a Pull Request.

Happy coding! 🧘‍♂️🍴
