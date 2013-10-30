#!/usr/bin/python

import sys    
sys.path.insert(0, '/usr/lib/python2.7/bridge/') 

from bridgeclient import BridgeClient

if len(sys.argv) < 2:
    print "Missing message."
    sys.exit(1)

bridge = BridgeClient()
msg = sys.argv[1]
print "Sending message: ", msg

bridge.send(msg) 
