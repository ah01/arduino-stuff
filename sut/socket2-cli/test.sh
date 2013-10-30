#!/bin/sh

# send "on" message to Arduino via Mailbox
python msgsend.py on

sleep 5

# send "off" message to Arduino via Mailbox
python msgsend.py off
