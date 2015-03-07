#!/usr/bin/env python

# $Id: fake_php.py,v 1.2 2003/08/22 22:52:52 chrisz Exp $

# fake php - all we really need is 'include schedulers.txt'

import os, sys

REQUEST_URI = os.environ['REQUEST_URI']

print 'Content-Type: text/plain'
print

print """--- FAKE PHP ---

[ REQUEST_URI=%s ]

Since I can't find php on your system, this stub program fake_php.py just
prints schedulers.txt as necessary.

"""%REQUEST_URI

if REQUEST_URI.endswith('/index.php'):
    sys.stdout.write(open('schedulers.txt').read())
