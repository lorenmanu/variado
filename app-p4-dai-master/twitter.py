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
class twitter:
	def GET(self2):
		page = 'twitter'
		# Consumer keys and access tokens, used for OAuth
		consumer_key = ""
		consumer_secret = ""
		access_token = ""
		access_token_secret = ""
		# OAuth process, using the keys and tokens
		auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
		auth.set_access_token(access_token, access_token_secret)
		# Creation of the actual interface, using authentication
		api = tweepy.API(auth)
		rajoy = api.get_user('marianorajoy')
		iglesias = api.get_user('Pablo_Iglesias_')
		pedro = api.get_user('sanchezcastejon')
		cayo = api.get_user('cayo_lara')
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']
		return main.render.index(**locals())

