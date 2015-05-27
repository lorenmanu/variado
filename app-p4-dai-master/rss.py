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
# etree sax parser
from lxml import etree

import urllib2
import sys

class rss:
	def GET(self2):
		page = 'rss'
		feed = feedparser.parse('http://www.20minutos.es/rss/minuteca/el-jueves/')
		items = feed["items"]
		logged_in = main.ses._initializer['logged_in']
		user = main.ses._initializer['user']

		# Parseamso el xml
		doc = etree.parse('./rss/portada.xml')

		# Obtenemos la información
		search_string = "la"
		search = doc.xpath("//title[contains(text(),'%s')]" % search_string) if search_string != "" else ""

		n_articulos = doc.xpath('count(//item)')
		n_imagenes = doc.xpath("count(//enclosure[@type='image/jpeg'])")
		imagenes = doc.xpath("//enclosure[@type='image/jpeg']")
		n_search = len(search)
		return main.render.index(**locals())
