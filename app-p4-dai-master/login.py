#!/usr/bin/env python
# -*- encoding: utf-8 -*-
import main
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
class login:
	# Mostrar el formulario
	def GET(self2):
		if main.ses._initializer['logged_in'] == True:
			page = 'index'
		else:
			page = 'login'
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())
	
	# Recoger los datos del formulario
	# si esta en base de datos page = 'loged'
	# sino page = 'login'
	# actualizar session
	def POST(self2):
		i = web.input()
		db = web.database(dbn="sqlite", db="users.db")
		q = db.select("users",where="username=$username",what="password",vars={"username": i.username})
		if q:
			db_password = list(q)[0]["password"]
			if db_password == md5(i.password).hexdigest():
				page = 'index'
				main.ses._initializer['logged_in'] = True
				main.ses._initializer['user'] = i.username
			else:
				page = 'login'
		else:
			page = 'login'
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())

