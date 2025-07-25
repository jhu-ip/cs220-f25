<html>
<body>

</ul>

<h4>Getting going with Unix
</h4>    <ul>
<li> CS Unix Accounts will be passed out - majors and minors should have a personal CS account; temporary class accounts for all others to be distributed</li>
 <li> Use PuTTY (Windows) or ssh (Mac Terminal) to connect to CS
 server remotely</li>
</ul>


<h4>Unix terminology:</h4>
<ul>
<li>  directory == folder containing files and other directories
<li>  ~ == home == origin of your files based on your login
<li>  . == current directory
<li>  .. == parent directory (up one level)
</ul>

<p><b>Important: change password with the <code>passwd</code> command!</b></p>

<p>Here are some of the most common unix commands:</p>
<ul>
<li><code>ls</code> - list contents of current directory
<li><code>pwd</code> - print working directory, to see the full path from home to current
<li><code>cat</code> - (short for concatenate) to view the contents of a file
<li><code>more</code> - to view a file with forward scrolling control
<li><code>less</code> - to view a file with two-way scrolling control
</ul>
</p>

<h4>Creating files:</h4>
<p>There are several options for creating and editing files:</p>
<ul>
<li>emacs - powerful editor, use Xming to run in visual mode
<li>vi/vim - another popular editor for programmers
</ul>
</p>


<h4>Working in Emacs:</h4>
<p>Most keyboard shortcuts for commands use either ^ (control key -
held while typing next character) or esc (escape key - press and
release before typing next character).  Editing takes place in a
buffer; save the buffer to overwrite previous file version.  Cutting
and pasting also works from a buffer (clipboard equivalent).
</p>

<pre>
^x^s  save file
^x^c  exit
^g    clears the commands, use this several times if you get in a weird state

^p  previous line (up)
^n  next line (down)
^b  backwards (left)  
^f  forward (right)  
^a  beginning of line 
^e  end of line

esc %  search & replace
^s  incremental search
^k  kill to end of line (stored in buffer)
^y  yank and insert from the buffer
^@  set mark (to indicate beginning of a selection)
esc w  copy selection (region from mark to cursor, copied to buffer)
^w  cut selection (stored in buffer, use ^-y yank to paste)

</pre>

<h4>Working in Vim:</h4>
<p>Vim has two distinct "states," called "insert mode" and "command mode".  In insert mode, vim works much like Windows Notepad, or any other simple text editor; when you press keys, the corresponding letters and symbols are added to the file at the location of the cursor.  Command mode is used for all the more advanced editing features such as cut/copy/paste, or moving the cursor around.
</p>
<p>
Hitting the escape key always switches you to command mode; if you're not sure what mode you're in, hit escape, and then you'll know you're in command mode.  If you're in command mode, hitting the 'a' key will get you into edit mode.  To save your file, get to command mode, type ":w", and hit enter.  To quit the program, get to command mode, type ":q", and hit enter.

In command mode, here are a few of the things you can do:
</p>

<pre>
File commands - type ":", then the command letter, then hit enter
:w save (<ul>w</ul>rite) your file
:q quit (exit from vim)
:q! force-quit (discards unsaved changes)

Commands to switch to Insert mode:
i start inserting text before cursor location
a start inserting text after cursor location
o start inserting on a new line below the current one
O start inserting on a new line above the current one

Movement commands:
h left a character
j down a line
k up a line
l right a character
f&lt;char&gt; fird first instance of &lt;char&gt; on this line
0 beginning of line
$ end of line
w next beginning of word
e next end of word
% jump to matching paren

Editing Commands:
yy copy (yank) line
y&lt;number&gt;y copy &lt;number&gt; lines
y&lt;movement command&gt; copy text covered by the movement command (e.g. yw to copy the next word)

dd cut (delete) line
d&lt;number&gt;d cut (delete) &lt;number&gt; lines
dw delete word

p paste (after cursor)
P paste (before cursor)
</pre>



</body>
</html>