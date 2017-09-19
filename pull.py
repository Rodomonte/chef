# chef pull

import os
from selenium.webdriver import Chrome

url_home = 'http://www.codechef.com/'
url_user = url_home + 'users/rodomonte/'

# POPULATE PMAP FROM PROFILE

pmap = {}

br = Chrome()
br.get(url_user)
html = br.page_source

html = html[html.find('Practice:'):]
while True:
  i = html.find('<p>')
  j = html.find('</article>')
  if i == -1 or j < i: break

  html = html[i+11:]
  i = html.find(':</strong>')
  contest = html[:i]

  probs = []
  while True:
    i = html.find('rodomonte')
    j = html.find('</span>')
    if i == -1 or j < i: break

    html = html[i+11:]
    i = html.find('</a>')
    prob = html[:i]
    probs += [prob]
  pmap[contest] = probs

# FETCH AND SAVE SUBMISSIONS

for contest in pmap:
  probs = pmap[contest]
  for prob in probs:
    br.get(url_home + '/' + contest + '/status/' + prob + ',rodomonte')
    html = br.page_source
    html = html[html.find('/misc/tick-icon.gif'):]

    for i in range(3):
      html = html[html.find('width')+5:]
    html = html[html.find('>'):]
    i = html.find('<')
    lang = html[1:i]
    if lang == 'C': suf = '.c'
    elif lang.startswith('C++'): suf = '.cc'
    elif lang.startswith('PY'): suf = '.py'
    else: suf = '.??'

    html = html[html.find('<a href=')+23:]
    i = html.find('" target')
    url_sub = url_home + 'viewplaintext/' + html[:i]

    br.get(url_sub)
    html = br.page_source
    html = html[html.find('<pre>')+5:]
    code = html[:html.find('</pre>')]
    code = code.replace('&lt;', '<')
    code = code.replace('&gt;', '>')
    code = code.replace('&amp;', '&')
    code = code.replace('\t', '  ')

    path = os.getcwd() + '\\' + contest
    if not os.path.exists(path):
      os.makedirs(path)
    path += '\\' + prob + suf
    if not os.path.exists(path):
      outfile = open(path, 'w')
      outfile.write(code)
      outfile.close()

br.quit()
