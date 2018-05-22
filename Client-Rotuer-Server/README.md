Client Rotuer Server
=

The fourth program is client server.

The communicate is between the client and the server via the router
When the router receives a message from the client:
1. the router chooses a random number uniformly from range [0,1].
2. If the number is greater than X it the router will forward the message, otherwise, it will drop the message (delete it).On the vice versa, the router always forwards any message from the server.

-X is an argument received from the command prompt. 

The client and the server can message each other from the command prompt freely, and when one side wants to disconnect he can do it by typing exit.
