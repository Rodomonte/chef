# chef report

from time import sleep
from selenium.webdriver import Chrome

user = 'rodomonte'
pw = 'agB3llreincarna'
url_home = 'http://www.codechef.com/'
url_user = url_home + 'users/' + user
url_chal = url_home + 'problems/challenge/'

def adv(text, item):
  i = text.find(item)
  return '' if i == -1 else text[i:]

codes = []
scores = []

br = Chrome()
br.get(url_home)
br.find_element_by_id('edit-name').send_keys(user)
br.find_element_by_id('edit-pass').send_keys(pw)
br.find_element_by_id('edit-submit').click()
sleep(3)
br.get(url_user)
uhtml = br.page_source
br.get(url_chal)
html = br.page_source

while True:
  html = adv(html, 'problemname')
  if html == '': break
  box = html[:html.find('</td>')]
  html = adv(html, '/problems/')
  codes += [html[10:html.find('">')]]
  scores += [0 if box.find('images/solved.png') == -1 else -1]

for i in range(len(codes)):
  if scores[i] == 0: continue
  br.get(url_home + 'status/' + codes[i] + ',' + user)
  html = adv(br.page_source, 'dataTable')
  html = html[:html.find('</table>')]
  html = adv(html, 'tick-icon')

  if html == '':
    html = adv(uhtml, 'Practice:')
    rec = html[:html.find('</article>')]
    while True:
      rec = adv(rec, '<p>')
      if rec == '':
        print('Error: Did not find '+codes[i]+' in contest record.')
        exit(0)
      line = rec[:rec.find('</p>')]
      if adv(line, codes[i]) != '':
        month = line[11:line.find(':</strong>')]
        break
      rec = adv(rec, '</p>')
    br.get(url_home + month + '/status/' + codes[i] + ',' + user)
    html = adv(br.page_source, 'dataTable')
    html = html[:html.find('</table>')]
    html = adv(html, 'tick-icon')
    if html == '':
      print('Error: Did not find successful submission for '+codes[i]+'.')
      exit(0)

  while True:
    html = adv(html, '[')
    scores[i] = max(scores[i], float(html[1:html.find('pts')]))
    html = adv(html, 'tick-icon')
    if html == '': break

m = {}
for i in range(len(codes)):
  m[codes[i]] = scores[i]
from operator import itemgetter
s = sorted(m.items(), key=itemgetter(1))
for p in s:
  print(p[0]+': '+str(p[1]))
br.quit()
