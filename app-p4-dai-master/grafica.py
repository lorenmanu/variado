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
form_grafica = form.Form(
    form.Textbox("Valor",
        form.notnull
    ),
    form.Button("Add"),
)
arraygeneral = []
class grafica:
	def GET(self2):
		page = 'grafica'
		array = arraygeneral[:]
		form = form_grafica
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())

	def POST(self2):
		i = web.input()
		if main.ses._initializer['logged_in'] == True:
			arraygeneral.append(int(i.Valor))
			array = arraygeneral[:]
		form = form_grafica
		page = 'grafica'
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())

