from os import listdir
import subprocess
code_dir = "code"
title = "#include <bits/stdc++.h>"

def get_sections():
    sections = []
    section_name = "Problemas"
    #os.chdir(os.path.dirname(__file__))

    subsections = []
    for line in listdir(code_dir):
        #print(line)
        #if len(tmp) == 1:
        #    raise ValueError('Subsection parse error: %s' % line)
        filename = line
        subsection_name = line.split('.')[0].replace('_', ' ')
        
        if subsection_name is None:
            raise ValueError('Subsection given without section')

        subsections.append((filename, subsection_name))
    

    if section_name is not None:
        sections.append((section_name, subsections))

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

def get_tex(sections):
    tex = ''
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        for (filename, subsection_name) in subsections:
            print(filename)
            tex += '\\subsection{%s}\n' % texify(subsection_name)
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s/%s}\n' % (get_style(filename), code_dir, filename)
            #tex += '\\hrulefill\n'
            tex += '\\clearpage\n'
        tex += '\\clearpage\n'
    return tex

if __name__ == "__main__":
    sections = get_sections()
    tex = get_tex(sections)
    with open('contents.tex', 'w') as f:
        f.write(tex)
    latexmk_options = ["latexmk", "-pdf", "notebook.tex"]
    subprocess.call(latexmk_options)
