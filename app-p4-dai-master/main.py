#!/usr/bin/env python
# -*- encoding: utf-8 -*-
import mako.runtime
mako.runtime.UNDEFINED = ''
import web
from web import form
import datetime
import json
import feedparser
from web.contrib.template import render_mako
import tweepy
from hashlib import md5

import rss
import grafica
import login
import logout
import mapa
import register
import twitter



from web.wsgiserver import CherryPyWSGIServer
CherryPyWSGIServer.ssl_certificate = "./static/prueba.crt"
CherryPyWSGIServer.ssl_private_key = "./static/pruebak.key"

# Lista de urls accesibles		
urls = (
        '/index', 'index',
        '/', 'index',
		'/rss', 'rss.rss',
		'/grafica', 'grafica.grafica',
		'/mapa', 'mapa.mapa',
		'/twitter', 'twitter.twitter',
		'/login', 'login.login',
		'/register', 'register.register',
		'/logout', 'logout.logout'
        )
app = web.application(urls, locals(), autoreload=True)
if web.config.get('_session') is None:
    ses = web.session.Session(
        app,
        web.session.DiskStore('sessions'),
          initializer={
            'logged_in': False,
            'user': '',
            'email': ''
          })
    web.config._session = ses
else:
    ses = web.config._session

render = render_mako(
        directories=['templates'],
        input_encoding='utf-8',
        output_encoding='utf-8',
        )
class index:
	def GET(self2):
		user = ''
		if ses._initializer['logged_in'] == True:
			user = ses._initializer['user']
		page = 'index'
		logged_in = ses._initializer['logged_in']
		user = ses._initializer['user']
		return render.index(**locals())

if __name__ == "__main__":
    app.run()
