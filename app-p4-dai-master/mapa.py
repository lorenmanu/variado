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
class mapa:
	def GET(self2):
		page = 'mapa'
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())
