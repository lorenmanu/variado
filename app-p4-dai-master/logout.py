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
class logout:
	def GET(self2):
		page = 'index'
		if main.ses._initializer['logged_in'] == True:
			main.ses._initializer['email'] = ''
			main.ses._initializer['user'] = ''
			main.ses._initializer['logged_in'] = False
		return main.render.index(**locals())
