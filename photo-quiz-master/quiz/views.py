# -*- coding: utf-8 -*-
from django.http import HttpResponse,HttpResponseRedirect
from django.template import RequestContext, loader
from quiz.models import *
import random
import md5
from django.core.context_processors import csrf
from django.shortcuts import render_to_response, redirect
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import login, authenticate, logout
from django.contrib.auth.decorators import login_required

def index(request):
    template = loader.get_template('index.html')
    context = RequestContext(request, {
        'totalpreguntas': Pregunta.objects.all().count(),
    })
    return HttpResponse(template.render(context))

def contact(request):
    template = loader.get_template('contact.html')
    context = RequestContext(request, {})
    return HttpResponse(template.render(context))

def help(request):
    template = loader.get_template('help.html')
    context = RequestContext(request, {})
    return HttpResponse(template.render(context))

def ranking(request):
    template = loader.get_template('ranking.html')
    listado = Usuario.objects.all().order_by('-puntos')
    context = RequestContext(request, {
            'modo': 'get',
            'listado': listado,
    })
    return HttpResponse(template.render(context))

def add(request):
    if request.method == 'GET':
        template = loader.get_template('add.html')
        context = RequestContext(request, {
            'modo': 'get',
            'mensaje': 'OK',
        })
        return HttpResponse(template.render(context))
    elif request.method == 'POST':
        template = loader.get_template('add.html')
        mensaje = 'OK'        
        if len(request.POST.get('Q')) < 1:
            mensaje = 'Rellene todos los campos'
        if len(request.POST.get('A')) < 1:
            mensaje = 'Rellene todos los campos'
        if len(request.POST.get('B')) < 1:
            mensaje = 'Rellene todos los campos'
        if len(request.POST.get('C')) < 1:
            mensaje = 'Rellene todos los campos'
        if len(request.POST.get('D')) < 1:
            mensaje = 'Rellene todos los campos'
        correct = 1
        if mensaje == 'OK':
            if request.POST.get('correcta') == 'A':
                correct = 1
            if request.POST.get('correcta') == 'B':
                correct = 2
            if request.POST.get('correcta') == 'C':
                correct = 3
            if request.POST.get('correcta') == 'D':
                correct = 4
            if request.POST.get('autor') != '':
                aut = request.POST.get('autor')
            print aut
            print request.POST.get('autor')
            user = Pregunta(imagen=request.FILES.get('img'),pregunta=request.POST.get('Q'),        respuesta1 = request.POST.get('A'),respuesta2 = request.POST.get('B'),respuesta3 = request.POST.get('C'),respuesta4 = request.POST.get('D'),correcta = correct,descripcion = request.POST.get('desc'),autor = aut,aciertos=0,fallos=0)
            user.save()
        context = RequestContext(request, {
            'modo': 'post',
            'mensaje': mensaje,
        })
        return HttpResponse(template.render(context))

def RegistrationView(request):
    if request.method == 'POST':
        formulario = UserCreationForm(request.POST)    
        if formulario.is_valid():
            formulario.save()
            new_user = Usuario(user = User.objects.last(),puntos=0)
            new_user.save()
            return HttpResponseRedirect('/quiz/')
    else:
        formulario = UserCreationForm()
    return render_to_response('register.html',{'formulario':formulario},context_instance=RequestContext(request))


def juego(request):
    if request.method == 'GET':
        template = loader.get_template('juego.html')
        size = Pregunta.objects.all().count()
        listado = Pregunta.objects.all()
        modo = 'get'
        indice = random.randrange(size)
        pregunta = listado[indice]
        puntos = 0
        if request.user.is_authenticated():
            users = Usuario.objects.all()
            for u in users:
                if u.user == request.user:
                    puntos = u.puntos
                    u.save()
        else:
            puntos = 0
        context = RequestContext(request, {
            'modo': modo,
            'pregunta': pregunta,
            'puntos': puntos,
        })
        return HttpResponse(template.render(context))
    elif request.method == 'POST':
        template = loader.get_template('juego.html')
        listado = Pregunta.objects.all()
        acierto = False
        if request.POST.get('A') and request.POST.get('Q') == '1':
            acierto = True
        if request.POST.get('B') and request.POST.get('Q') == '2':
            acierto = True
        if request.POST.get('C') and request.POST.get('Q') == '3':
            acierto = True
        if request.POST.get('D') and request.POST.get('Q') == '4':
            acierto = True
        aciertos = 0
        fallos = 0
        p = Pregunta.objects.filter(pregunta=request.POST.get('Question'))[0]
        if acierto:
            puntos = 0
            mensaje = "Enhorabuena"
            p.aciertos = p.aciertos + 1
            if request.user.is_authenticated():
                users = Usuario.objects.all()
                for u in users:
                    if u.user == request.user:
                        u.puntos = u.puntos + 1
                        puntos = u.puntos
                        u.save()
        else:
            puntos = 0
            if request.user.is_authenticated():
                users = Usuario.objects.all()
                for u in users:
                    if u.user == request.user:
                        u.puntos = u.puntos - 1
                        if u.puntos < 0:
                            u.puntos = 0
                        puntos = u.puntos
                        u.save()
            mensaje = u"Falló"
            p.fallos = p.fallos + 1
        aciertos = p.aciertos
        fallos = p.fallos
        p.save()
        aciertosp = (100.0/(aciertos+fallos))*aciertos
        fallosp = (100.0/(aciertos+fallos))*fallos
        context = RequestContext(request, {
            'modo': 'post',
            'mensaje': mensaje,
            'img': request.POST.get('img'),
            'desc': request.POST.get('desc'),
            'puntos': puntos,
            'aciertos': aciertos,
            'fallos': fallos,
            'aciertosp': aciertosp,
            'fallosp': fallosp,
        })
        return HttpResponse(template.render(context))
