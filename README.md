# Kiva Simulation

## Implementation Notes

0. This program is based on a few papers: "SIPP: Safe Interval Path Planning for Dynamic Environments",
 "Complete decentralized method for on-line multi-robot trajectory planning in well-formed infrastructures",
 "Lifelong Multi-Agent Path Finding for Online Pickup and Delivery Tasks",
 "Persistent and Robust Execution of MAPF Schedules in Warehouses".

1. In this project communication between modules is written
as function call(receiver maintains a message queue with lock),
as compare to using RPC systems like Stubby. The advantage of this
approach is lighter weight, the disadvantage is having this non-standard
setup needs more reasoning.

2. Currently the program is coupled. Assume modules communicate with
message over internet may make the program structure cleaner.

3. For all message queue, the sender can send in an async way, the receiver should copy and process.
## Lessons Learned

1. A large program must be able to be tested separately. To achieve this APIs
between components needs to be defined. There needs to be an API class and an implementation class.

2. The program shows strange behavior with -O2 turned on, should avoid -O2.