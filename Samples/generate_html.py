#!/usr/bin/python
from html import escape  # python 3.x
import os
code_dir = "code"
title = "#include <bits/stdc++.h>"

def get_sections():
    sections = []
    section_name = None
    with open('contents.txt', 'r') as f:
        for line in f:
            if '#' in line: line = line[:line.find('#')]
            line = line.strip()
            if len(line) == 0: continue
            if line[0] == '[':
                section_name = line[1:-1]
                subsections = []
                if section_name is not None:
                    sections.append((section_name, subsections))
            else:
                tmp = line.split('\t', 1)
                if len(tmp) == 1:
                    raise ValueError('Subsection parse error: %s' % line)
                filename = tmp[0]
                subsection_name = tmp[1]
                if subsection_name is None:
                    raise ValueError('Subsection given without section')
                subsections.append((filename, subsection_name))
    return sections

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:
        return 'txt'

# TODO: check if this is everything we need
def texify(s):
    #s = s.replace('\'', '\\\'')
    #s = s.replace('\"', '\\\"')
    return s

def get_html(sections):
    html = """
    <script src="https://cdn.rawgit.com/google/code-prettify/master/loader/run_prettify.js"></script>
    <style>
        * {
            font-family: Segoe UI, sans-serif;
        }

        .prettyprint span {
            font-family: Consolas, monospace;
        }

        ol { 
            padding: 0;
            list-style-type: none;
        }

        #index {
            font-size: 0.6rem;
        }

        #index li {
            cursor: pointer;
        }
    </style>
    """
    html += '<ol id="index">'
    for idx, (section_name, subsections) in enumerate(sections):
        html += '<h2><li>' + str(idx + 1) + '. ' + section_name + '</li><ol></h2><ol>'
        for idx2, (filename, subsection_name) in enumerate(subsections):
            html += '<h3><li onClick="document.getElementById(\'' + filename + '\').scrollIntoView()">' + str(idx + 1) + '.' + str(idx2 + 1) + '. ' + subsection_name + '</li></h3>'
        html += '</ol>'
    html += '</ol>'

    html += '<ol>'
    for idx, (section_name, subsections) in enumerate(sections):
        html += '<h1><li>' + str(idx + 1) + '. ' + section_name + '</li></h1>'
        html += '<ol>'
        for idx2, (filename, subsection_name) in enumerate(subsections):
            html += '<h2><li id="'+ filename + '">' + str(idx + 1) + '.' + str(idx2 + 1) + '. ' + subsection_name + '</li></h2>'
            html += '<pre class="prettyprint">'
            with open(code_dir + '/' + filename, 'r') as f:
                html += escape(f.read())
            html += '</pre>'
        html += '</ol>'
    html += '</ol>'
    return html

if __name__ == "__main__":
    sections = get_sections()
    html = get_html(sections)
    with open('index.html', 'w') as f:
        f.write(html)
    os.system('copy index.html /A /Y ..\docs\index.html')