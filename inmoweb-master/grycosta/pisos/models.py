from django.db import models
TIPO_INMUEBLE = (
    ('Piso','Piso'),
    ('Atico','Atico'),
    ('Apartamento','Apartamento'),
    ('Casa','Casa'),
    ('Local','Local'),
    ('Oficina','Oficina'),
    ('Garaje','Garaje'),
)

class Alquiler(models.Model):
    id = models.AutoField(primary_key=True)
    zona = models.CharField(max_length=40,blank=False,null=False)
    precio = models.IntegerField(default=0,blank=False,null=False)
    habitaciones = models.IntegerField(default=0)
    aseos = models.IntegerField(default=0)
    cochera = models.BooleanField(default=None)
    calefaccion = models.BooleanField(default=None)
    amueblado = models.BooleanField(default=None)
    tipo = models.CharField(max_length=12,choices=TIPO_INMUEBLE,default='piso')
    eficiencia = models.CharField(max_length=64,blank=False,null=False,default=" ")
    imagen1 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen2 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen3 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen4 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen5 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen6 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    descripcion = models.TextField(default=" ")
    def __unicode__(self):
        return u'Piso ' + unicode(self.id)


class Venta(models.Model):
    id = models.AutoField(primary_key=True)
    zona = models.CharField(max_length=40,blank=False,null=False)
    precio = models.IntegerField(default=0,blank=False,null=False)
    habitaciones = models.IntegerField(default=0)
    aseos = models.IntegerField(default=0)
    cochera = models.BooleanField(default=None)
    calefaccion = models.BooleanField(default=None)
    tipo = models.CharField(max_length=12,choices=TIPO_INMUEBLE,default='piso')
    eficiencia = models.CharField(max_length=64,blank=False,null=False,default=" ")
    imagen1 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen2 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen3 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen4 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen5 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen6 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen7 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen8 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    imagen9 = models.ImageField(upload_to='static/',default='static/no-img.jpg')
    descripcion = models.TextField(default=" ")
    def __unicode__(self):
        return u'Piso ' + unicode(self.id)
