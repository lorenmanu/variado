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
def checkpassword(cad,cad2):
	i = 0
	cont = 0
	while i < len(cad):
		if cad[i].isdigit():
			cont += 1
		i += 1
	if cont == 0:
		return "El password debe contener numeros y letras"
	if len(cad) < 4:
		return "El password debe tener mas de 4 cifras"
	if cad != cad2:
		return "Los password no coinciden"
	return "ok"

class register:
	# Mostrar formulario
	def GET(self2):
		error = ""
		page = 'register'
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())

	# Recoger datos del formulario
	# si el usuario no esta ya en base de datos
	# page = 'registered' y además guardar en base de datos
	# sino page = 'register'
	def POST(self2):
		page = 'index'
		i = web.input()
		error = checkpassword(i.password,i.passwordagain)
		if not i.username or not i.password or len(error) > 5:
			page = 'register'
		else:
			db = web.database(dbn="sqlite", db="users.db")
			q = db.select("users",where="username=$username",what="password",vars={"username": i.username})
			if q:
				page = 'register'
				error = "Usuario ya registrado!"
			else:
				db.insert("users",username=i.username,password=md5(i.password).hexdigest())
				main.ses._initializer['logged_in'] = True
				main.ses._initializer['user'] = i.username
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())

