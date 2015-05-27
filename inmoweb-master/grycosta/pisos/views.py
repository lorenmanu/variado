# -*- coding: utf-8 -*-
from django.http import HttpResponse
from django.template import RequestContext, loader
from pisos.models import Alquiler,Venta

def index(request):
	template = loader.get_template('index.html')
	context = RequestContext(request,{})
	return HttpResponse(template.render(context))

def filtrar_alquiler(request):
	listado = Alquiler.objects.order_by('-id')[:5]
	listado_final = []
	for l in listado:
		# precio
		ok = True
		if request.POST.get('precio') != 'Cualquiera':
			if request.POST.get('precio') == u'50€-100€':
				if int(l.precio) < 50 or int(l.precio) > 100:
					ok = False
			if request.POST.get('precio') == u'101€-200€':
				if int(l.precio) < 101 or int(l.precio) > 200:
					ok = False			
			if request.POST.get('precio') == u'201€-400€':
				if int(l.precio) < 201 or int(l.precio) > 400:
					ok = False
			if request.POST.get('precio') == u'+400€':
				if int(l.precio) < 400:
					ok = False

		# num habitaciones
		if request.POST.get('habitaciones') != 'Cualquiera':
			if request.POST.get('habitaciones') == u'1':
				if int(l.habitaciones) != 1:
					ok = False
			if request.POST.get('habitaciones') == u'2':
				if int(l.habitaciones) != 2:
					ok = False			
			if request.POST.get('habitaciones') == u'3':
				if int(l.habitaciones) != 3:
					ok = False
			if request.POST.get('habitaciones') == u'+4':
				if int(l.habitaciones) < 4:
					ok = False


		# num aseos
		if request.POST.get('aseos') != 'Cualquiera':
			if request.POST.get('aseos') == u'1':
				if int(l.aseos) != 1:
					ok = False
			if request.POST.get('aseos') == u'2':
				if int(l.aseos) != 2:
					ok = False			
			if request.POST.get('aseos') == u'3':
				if int(l.aseos) != 3:
					ok = False
			if request.POST.get('aseos') == u'+4':
				if int(l.aseos) < 4:
					ok = False

		# calefaccion
		if request.POST.get('calefaccion') != u'Cualquiera':
			if request.POST.get('calefaccion') == u'Si':			
				if l.calefaccion == False:
					ok = False
			if request.POST.get('calefaccion') == u'No':			
				if l.calefaccion == True:
					ok = False
		# cochera
		if request.POST.get('cochera') != u'Cualquiera':
			if request.POST.get('cochera') == u'Si':			
				if l.cochera == False:
					ok = False
			if request.POST.get('cochera') == u'No':			
				if l.cochera == True:
					ok = False

		if ok:
			listado_final.append(l)
			
	return listado_final

def filtrar_venta(request):
	listado = Venta.objects.order_by('-id')[:5]
	listado_final = []
	for l in listado:
		# precio
		ok = True
		if request.POST.get('precio') != 'Cualquiera':
			if request.POST.get('precio') == u'50€-100€':
				if int(l.precio) < 50 or int(l.precio) > 100:
					ok = False
			if request.POST.get('precio') == u'101€-200€':
				if int(l.precio) < 101 or int(l.precio) > 200:
					ok = False			
			if request.POST.get('precio') == u'201€-400€':
				if int(l.precio) < 201 or int(l.precio) > 400:
					ok = False
			if request.POST.get('precio') == u'+400€':
				if int(l.precio) < 400:
					ok = False

		# num habitaciones
		if request.POST.get('habitaciones') != 'Cualquiera':
			if request.POST.get('habitaciones') == u'1':
				if int(l.habitaciones) != 1:
					ok = False
			if request.POST.get('habitaciones') == u'2':
				if int(l.habitaciones) != 2:
					ok = False			
			if request.POST.get('habitaciones') == u'3':
				if int(l.habitaciones) != 3:
					ok = False
			if request.POST.get('habitaciones') == u'+4':
				if int(l.habitaciones) < 4:
					ok = False


		# num aseos
		if request.POST.get('aseos') != 'Cualquiera':
			if request.POST.get('aseos') == u'1':
				if int(l.aseos) != 1:
					ok = False
			if request.POST.get('aseos') == u'2':
				if int(l.aseos) != 2:
					ok = False			
			if request.POST.get('aseos') == u'3':
				if int(l.aseos) != 3:
					ok = False
			if request.POST.get('aseos') == u'+4':
				if int(l.aseos) < 4:
					ok = False

		# calefaccion
		if request.POST.get('calefaccion') != u'Cualquiera':
			if request.POST.get('calefaccion') == u'Si':			
				if l.calefaccion == False:
					ok = False
			if request.POST.get('calefaccion') == u'No':			
				if l.calefaccion == True:
					ok = False
		# cochera
		if request.POST.get('cochera') != u'Cualquiera':
			if request.POST.get('cochera') == u'Si':			
				if l.cochera == False:
					ok = False
			if request.POST.get('cochera') == u'No':			
				if l.cochera == True:
					ok = False

		if ok:
			listado_final.append(l)
			
	return listado_final



def buscador(request):
	if request.method == 'GET':
		template = loader.get_template('buscador.html')
		context = RequestContext(request, {
	        'modo': 'get',
	    })
		return HttpResponse(template.render(context))
	elif request.method == 'POST':
		template = loader.get_template('buscador.html')
		listado = filtrar_alquiler(request)
		context = RequestContext(request, {
	        'modo': 'post',
			'listado': listado,
	    })
		return HttpResponse(template.render(context))

def buscador2(request):
	if request.method == 'GET':
		template = loader.get_template('buscador2.html')
		context = RequestContext(request, {
	        'modo': 'get',
	    })
		return HttpResponse(template.render(context))
	elif request.method == 'POST':
		template = loader.get_template('buscador2.html')
		listado = filtrar_venta(request)
		context = RequestContext(request, {
	        'modo': 'post',
			'listado': listado,
	    })
		return HttpResponse(template.render(context))

def contact(request):
	template = loader.get_template('contact.html')
	context = RequestContext(request,{})
	return HttpResponse(template.render(context))

