from django.db import models
from django.contrib.auth.models import User
class Pregunta(models.Model):
    id = models.AutoField(primary_key=True)
    imagen = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    pregunta = models.CharField(max_length=256,blank=False,null=False)
    respuesta1 = models.CharField(max_length=64,blank=False,null=False)
    respuesta2 = models.CharField(max_length=64,blank=False,null=False)
    respuesta3 = models.CharField(max_length=64,blank=False,null=False)
    respuesta4 = models.CharField(max_length=64,blank=False,null=False)
    correcta = models.IntegerField(default=1,blank=False,null=False)
    descripcion = models.CharField(max_length=64,blank=True,null=True)
    autor = models.CharField(max_length=64,blank=True,null=True)
    aciertos = models.IntegerField(default=0,blank=True,null=True)
    fallos = models.IntegerField(default=0,blank=True,null=True)
    def __unicode__(self):
        return u'Pregunta ' + unicode(self.id)

class Usuario(models.Model):
    user = models.ForeignKey(User, unique=True)
    puntos = models.IntegerField(default=0,blank=False,null=False)

