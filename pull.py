# chef pull

from selenium.webdriver import Chrome

dir_home = 'C:\\System\\chef\\pull'
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
    html = html[html.find('<a href=')+23:]
    i = html.find('" target')
    url_sub = url_home + 'viewplaintext/' + html[:i]

    br.get(url_sub)
    code = br.page_source

    #! CREATE DIR, SAVE FILE

br.quit()
