import os, requests, sys

url = 'https://api.github.com/gists'
ext = 'txt'

if os.isatty(0):
    filename = sys.argv[1]
    with open(filename) as fh:
        content = fh.read()
        if '.' in filename:
            ext = filename.split('.')[-1]
else:
    content = sys.stdin.read()

r = requests.post(url, json={
    'files': {
        'file1.' + ext: {
            'content': content
        }
    }
})

print(r.json()['html_url'])