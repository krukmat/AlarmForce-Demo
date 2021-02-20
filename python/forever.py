#!/usr/bin/python3
from subprocess import Popen
import sys

filename = './salesforce.py'
while True:
    print("\nStarting " + filename)
    p = Popen("python3 " + filename, shell=True)
    p.wait()