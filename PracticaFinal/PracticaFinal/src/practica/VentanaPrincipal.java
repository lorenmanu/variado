/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica;

import Formas.Elipse;
import Formas.Rectangulo;
import java.awt.Color;
import java.awt.Image;
import java.awt.geom.AffineTransform;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.media.Buffer;
import javax.media.control.FrameGrabbingControl;
import javax.media.format.VideoFormat;
import javax.media.util.BufferToImage;
import javax.swing.JColorChooser;
import javax.swing.JFileChooser;

public class VentanaPrincipal extends javax.swing.JFrame {

    File file = null;
    VentanaInternaJMF v_jmf = null;

    public VentanaPrincipal() {
        initComponents();

    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenu1 = new javax.swing.JMenu();
        Barra_de_herramientas = new javax.swing.JToolBar();
        lapiz = new javax.swing.JButton();
        linea = new javax.swing.JButton();
        rectangulo = new javax.swing.JButton();
        ovalo = new javax.swing.JButton();
        rectangulo_redondo = new javax.swing.JButton();
        curva = new javax.swing.JButton();
        dibujo = new javax.swing.JPanel();
        opciones_dibujo = new javax.swing.JPanel();
        panel_colores = new javax.swing.JPanel();
        butt_blanco = new javax.swing.JButton();
        butt_negro = new javax.swing.JButton();
        butt_amarillo = new javax.swing.JButton();
        butt_verde = new javax.swing.JButton();
        butt_rojo = new javax.swing.JButton();
        butt_azul = new javax.swing.JButton();
        boton_mas_colores = new javax.swing.JButton();
        panel_opciones_figura = new javax.swing.JPanel();
        grosor_relleno = new javax.swing.JPanel();
        grosor = new javax.swing.JPanel();
        indicador_grosor = new javax.swing.JSpinner();
        texto_grosor = new javax.swing.JLabel();
        jComboBox2 = new javax.swing.JComboBox();
        jLabel2 = new javax.swing.JLabel();
        relleno_editar = new javax.swing.JPanel();
        selecionar_figura = new javax.swing.JRadioButton();
        relleno = new javax.swing.JRadioButton();
        transparencia = new javax.swing.JRadioButton();
        boton_discontinuo = new javax.swing.JRadioButton();
        operaciones_imagen = new javax.swing.JPanel();
        Etiqueta_Imagen1 = new javax.swing.JLabel();
        jComboBox1 = new javax.swing.JComboBox();
        Etiqueta_Imagen2 = new javax.swing.JLabel();
        barra_brillo = new javax.swing.JSlider();
        etiqueta_brillo = new javax.swing.JLabel();
        barra_umbralizacion = new javax.swing.JSlider();
        botonRestar = new javax.swing.JToggleButton();
        botonDisminuir = new javax.swing.JButton();
        botonAumentar = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        etiqueta_umbral = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        escritorio = new javax.swing.JDesktopPane();
        herramienta_seleccionada = new javax.swing.JLabel();
        menu_opciones_archivo = new javax.swing.JMenuBar();
        Archivo = new javax.swing.JMenu();
        Nuevo = new javax.swing.JMenuItem();
        Abrir = new javax.swing.JMenuItem();
        Guardar = new javax.swing.JMenuItem();
        jMenuItem1 = new javax.swing.JMenuItem();
        BotonGrabarSonido = new javax.swing.JMenuItem();
        botonVideoJMF = new javax.swing.JMenuItem();
        Edicion = new javax.swing.JMenu();
        v_barraestado = new javax.swing.JCheckBoxMenuItem();
        v_barraformas = new javax.swing.JCheckBoxMenuItem();
        v_barraatributos = new javax.swing.JCheckBoxMenuItem();

        FormListener formListener = new FormListener();

        jMenu1.setText("jMenu1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        Barra_de_herramientas.setRollover(true);

        lapiz.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/punto.png"))); // NOI18N
        lapiz.setBorderPainted(false);
        lapiz.setFocusable(false);
        lapiz.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        lapiz.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        lapiz.addMouseListener(formListener);
        Barra_de_herramientas.add(lapiz);

        linea.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/linea.png"))); // NOI18N
        linea.setFocusable(false);
        linea.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        linea.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        linea.addMouseListener(formListener);
        Barra_de_herramientas.add(linea);

        rectangulo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/rectangulo.png"))); // NOI18N
        rectangulo.setFocusable(false);
        rectangulo.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        rectangulo.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        rectangulo.addMouseListener(formListener);
        Barra_de_herramientas.add(rectangulo);

        ovalo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/elipse.png"))); // NOI18N
        ovalo.setFocusable(false);
        ovalo.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        ovalo.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        ovalo.addMouseListener(formListener);
        Barra_de_herramientas.add(ovalo);

        rectangulo_redondo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/elipse.png"))); // NOI18N
        rectangulo_redondo.setFocusable(false);
        rectangulo_redondo.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        rectangulo_redondo.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        rectangulo_redondo.addMouseListener(formListener);
        Barra_de_herramientas.add(rectangulo_redondo);

        curva.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/elipse.png"))); // NOI18N
        curva.setFocusable(false);
        curva.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        curva.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        curva.addMouseListener(formListener);
        Barra_de_herramientas.add(curva);

        getContentPane().add(Barra_de_herramientas, java.awt.BorderLayout.PAGE_START);

        dibujo.setLayout(new java.awt.BorderLayout());

        opciones_dibujo.setBorder(javax.swing.BorderFactory.createMatteBorder(2, 2, 2, 2, new java.awt.Color(102, 102, 255)));
        opciones_dibujo.setLayout(new java.awt.BorderLayout());

        butt_blanco.setBackground(java.awt.Color.white);
        butt_blanco.addMouseListener(formListener);

        butt_negro.setBackground(java.awt.Color.black);
        butt_negro.addMouseListener(formListener);

        butt_amarillo.setBackground(java.awt.Color.yellow);
        butt_amarillo.addMouseListener(formListener);

        butt_verde.setBackground(java.awt.Color.green);
        butt_verde.addMouseListener(formListener);

        butt_rojo.setBackground(java.awt.Color.red);
        butt_rojo.addMouseListener(formListener);

        butt_azul.setBackground(java.awt.Color.blue);
        butt_azul.addMouseListener(formListener);

        boton_mas_colores.setText("Más");
        boton_mas_colores.addActionListener(formListener);

        javax.swing.GroupLayout panel_coloresLayout = new javax.swing.GroupLayout(panel_colores);
        panel_colores.setLayout(panel_coloresLayout);
        panel_coloresLayout.setHorizontalGroup(
            panel_coloresLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panel_coloresLayout.createSequentialGroup()
                .addGroup(panel_coloresLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(panel_coloresLayout.createSequentialGroup()
                        .addComponent(butt_negro, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, 0)
                        .addComponent(butt_rojo, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, 0)
                        .addComponent(butt_azul, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(panel_coloresLayout.createSequentialGroup()
                        .addComponent(butt_blanco, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, 0)
                        .addComponent(butt_amarillo, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, 0)
                        .addComponent(butt_verde, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(0, 0, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, panel_coloresLayout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(boton_mas_colores))
        );
        panel_coloresLayout.setVerticalGroup(
            panel_coloresLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panel_coloresLayout.createSequentialGroup()
                .addGroup(panel_coloresLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(butt_negro, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(butt_rojo, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(butt_azul, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGroup(panel_coloresLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(butt_blanco, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(butt_amarillo, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(butt_verde, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(boton_mas_colores)
                .addContainerGap())
        );

        opciones_dibujo.add(panel_colores, java.awt.BorderLayout.WEST);

        panel_opciones_figura.setBorder(javax.swing.BorderFactory.createEmptyBorder(1, 1, 1, 1));
        panel_opciones_figura.setLayout(new java.awt.BorderLayout());

        grosor_relleno.setLayout(new java.awt.BorderLayout());

        grosor.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.LOWERED, null, java.awt.Color.gray, null, null));

        indicador_grosor.addChangeListener(formListener);

        texto_grosor.setText("Grosor");

        jComboBox2.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Ninguno", "Vertical", "Horizontal", "Diagonal" }));
        jComboBox2.addActionListener(formListener);

        jLabel2.setText("Degradado");

        javax.swing.GroupLayout grosorLayout = new javax.swing.GroupLayout(grosor);
        grosor.setLayout(grosorLayout);
        grosorLayout.setHorizontalGroup(
            grosorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(grosorLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(grosorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(indicador_grosor)
                    .addGroup(grosorLayout.createSequentialGroup()
                        .addGroup(grosorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(texto_grosor)
                            .addComponent(jLabel2)
                            .addComponent(jComboBox2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        grosorLayout.setVerticalGroup(
            grosorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(grosorLayout.createSequentialGroup()
                .addComponent(texto_grosor)
                .addGap(3, 3, 3)
                .addComponent(indicador_grosor, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 15, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jComboBox2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(36, Short.MAX_VALUE))
        );

        grosor_relleno.add(grosor, java.awt.BorderLayout.WEST);

        relleno_editar.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.LOWERED, null, java.awt.Color.gray, null, null));
        relleno_editar.setLayout(new javax.swing.BoxLayout(relleno_editar, javax.swing.BoxLayout.LINE_AXIS));

        selecionar_figura.setText("Editar");
        selecionar_figura.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        selecionar_figura.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        selecionar_figura.addMouseListener(formListener);
        relleno_editar.add(selecionar_figura);

        relleno.setText("Relleno");
        relleno.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        relleno.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        relleno.addMouseListener(formListener);
        relleno.addActionListener(formListener);
        relleno_editar.add(relleno);

        transparencia.setText("Transparencia");
        transparencia.addMouseListener(formListener);
        transparencia.addActionListener(formListener);
        relleno_editar.add(transparencia);

        boton_discontinuo.setText("Discontinuo");
        boton_discontinuo.addActionListener(formListener);
        relleno_editar.add(boton_discontinuo);

        grosor_relleno.add(relleno_editar, java.awt.BorderLayout.CENTER);

        panel_opciones_figura.add(grosor_relleno, java.awt.BorderLayout.WEST);

        operaciones_imagen.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED, null, java.awt.Color.gray, null, null));

        Etiqueta_Imagen1.setText("Propiedades de Imagen");
        Etiqueta_Imagen1.addMouseListener(formListener);

        jComboBox1.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "No aplicar ninguno", "emborramiento media", "emborramiento binomial", "enfoque", "relieve", "detector fronteras", "contraste", "iluminación", "oscurecer" }));
        jComboBox1.addActionListener(formListener);

        Etiqueta_Imagen2.setText("Efectos sobre el Color");

        barra_brillo.addChangeListener(formListener);

        etiqueta_brillo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/iluminar.png"))); // NOI18N
        etiqueta_brillo.setText("Deslizador Brillo");

        barra_umbralizacion.setMaximum(255);
        barra_umbralizacion.setValue(0);
        barra_umbralizacion.setMinimumSize(new java.awt.Dimension(200, 120));
        barra_umbralizacion.addMouseMotionListener(formListener);

        botonRestar.setText("Restar Imagen");
        botonRestar.addMouseListener(formListener);

        botonDisminuir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/disminuir.png"))); // NOI18N
        botonDisminuir.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        botonDisminuir.setMaximumSize(new java.awt.Dimension(50, 35));
        botonDisminuir.setMinimumSize(new java.awt.Dimension(50, 35));
        botonDisminuir.setPreferredSize(new java.awt.Dimension(50, 35));
        botonDisminuir.addActionListener(formListener);

        botonAumentar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/aumentar.png"))); // NOI18N
        botonAumentar.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        botonAumentar.setMaximumSize(new java.awt.Dimension(50, 35));
        botonAumentar.setMinimumSize(new java.awt.Dimension(50, 35));
        botonAumentar.setPreferredSize(new java.awt.Dimension(50, 35));
        botonAumentar.addActionListener(formListener);

        jButton1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/Capturar.png"))); // NOI18N
        jButton1.setText("Capturar");
        jButton1.addMouseListener(formListener);

        etiqueta_umbral.setText("Umbralizacion");

        jLabel1.setText("Escalado");

        javax.swing.GroupLayout operaciones_imagenLayout = new javax.swing.GroupLayout(operaciones_imagen);
        operaciones_imagen.setLayout(operaciones_imagenLayout);
        operaciones_imagenLayout.setHorizontalGroup(
            operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(operaciones_imagenLayout.createSequentialGroup()
                .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(operaciones_imagenLayout.createSequentialGroup()
                        .addGap(7, 7, 7)
                        .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(operaciones_imagenLayout.createSequentialGroup()
                                .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(49, 49, 49)
                                .addComponent(etiqueta_brillo, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(operaciones_imagenLayout.createSequentialGroup()
                                .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(operaciones_imagenLayout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addComponent(Etiqueta_Imagen2))
                                    .addComponent(Etiqueta_Imagen1, javax.swing.GroupLayout.PREFERRED_SIZE, 150, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(30, 30, 30)
                                .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(barra_umbralizacion, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(barra_brillo, javax.swing.GroupLayout.PREFERRED_SIZE, 170, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, operaciones_imagenLayout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(etiqueta_umbral)
                        .addGap(98, 98, 98)))
                .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(operaciones_imagenLayout.createSequentialGroup()
                        .addGap(94, 94, 94)
                        .addComponent(jLabel1)
                        .addGap(71, 71, 71)
                        .addComponent(jButton1))
                    .addGroup(operaciones_imagenLayout.createSequentialGroup()
                        .addGap(62, 62, 62)
                        .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(botonRestar)
                            .addGroup(operaciones_imagenLayout.createSequentialGroup()
                                .addComponent(botonDisminuir, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(botonAumentar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        operaciones_imagenLayout.setVerticalGroup(
            operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(operaciones_imagenLayout.createSequentialGroup()
                .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(operaciones_imagenLayout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(etiqueta_umbral)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(barra_umbralizacion, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(operaciones_imagenLayout.createSequentialGroup()
                                .addGap(26, 26, 26)
                                .addComponent(barra_brillo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(etiqueta_brillo)))
                    .addGroup(operaciones_imagenLayout.createSequentialGroup()
                        .addGap(6, 6, 6)
                        .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(Etiqueta_Imagen2)
                            .addGroup(operaciones_imagenLayout.createSequentialGroup()
                                .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(botonRestar, javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(Etiqueta_Imagen1))
                                .addGap(2, 2, 2)
                                .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(jLabel1)
                                    .addComponent(jButton1))))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(operaciones_imagenLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(botonDisminuir, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(botonAumentar, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(1, 1, 1))
        );

        panel_opciones_figura.add(operaciones_imagen, java.awt.BorderLayout.CENTER);

        opciones_dibujo.add(panel_opciones_figura, java.awt.BorderLayout.CENTER);

        dibujo.add(opciones_dibujo, java.awt.BorderLayout.SOUTH);

        javax.swing.GroupLayout escritorioLayout = new javax.swing.GroupLayout(escritorio);
        escritorio.setLayout(escritorioLayout);
        escritorioLayout.setHorizontalGroup(
            escritorioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 1505, Short.MAX_VALUE)
        );
        escritorioLayout.setVerticalGroup(
            escritorioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 469, Short.MAX_VALUE)
        );

        dibujo.add(escritorio, java.awt.BorderLayout.CENTER);

        getContentPane().add(dibujo, java.awt.BorderLayout.CENTER);

        herramienta_seleccionada.setText("Ninguna");
        herramienta_seleccionada.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        getContentPane().add(herramienta_seleccionada, java.awt.BorderLayout.PAGE_END);

        Archivo.setText("Archivo");

        Nuevo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/nuevo.png"))); // NOI18N
        Nuevo.setText("Nuevo");
        Nuevo.addMouseListener(formListener);
        Archivo.add(Nuevo);

        Abrir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/abrir.png"))); // NOI18N
        Abrir.setText("Abrir");
        Abrir.addMouseListener(formListener);
        Archivo.add(Abrir);

        Guardar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/Guardar.gif"))); // NOI18N
        Guardar.setText("Guardar");
        Guardar.addMouseListener(formListener);
        Archivo.add(Guardar);

        jMenuItem1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/openAudio24x24.png"))); // NOI18N
        jMenuItem1.setText("Abrir Sonido");
        jMenuItem1.addMouseListener(formListener);
        jMenuItem1.addActionListener(formListener);
        Archivo.add(jMenuItem1);

        BotonGrabarSonido.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/record24x24.png"))); // NOI18N
        BotonGrabarSonido.setText("Grabar Sonido");
        BotonGrabarSonido.addMouseListener(formListener);
        Archivo.add(BotonGrabarSonido);

        botonVideoJMF.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/AbrirMedio.png"))); // NOI18N
        botonVideoJMF.setText("VideoJMF");
        botonVideoJMF.addMouseListener(formListener);
        Archivo.add(botonVideoJMF);

        menu_opciones_archivo.add(Archivo);

        Edicion.setText("Edición");

        v_barraestado.setSelected(true);
        v_barraestado.setText("Ver barra de estado");
        v_barraestado.addMouseListener(formListener);
        Edicion.add(v_barraestado);

        v_barraformas.setSelected(true);
        v_barraformas.setText("Ver barra de formas");
        v_barraformas.addMouseListener(formListener);
        v_barraformas.addActionListener(formListener);
        Edicion.add(v_barraformas);

        v_barraatributos.setSelected(true);
        v_barraatributos.setText("Ver barra de atributos");
        v_barraatributos.addMouseListener(formListener);
        v_barraatributos.addActionListener(formListener);
        Edicion.add(v_barraatributos);

        menu_opciones_archivo.add(Edicion);

        setJMenuBar(menu_opciones_archivo);

        pack();
    }

    // Code for dispatching events from components to event handlers.

    private class FormListener implements java.awt.event.ActionListener, java.awt.event.MouseListener, java.awt.event.MouseMotionListener, javax.swing.event.ChangeListener {
        FormListener() {}
        public void actionPerformed(java.awt.event.ActionEvent evt) {
            if (evt.getSource() == relleno) {
                VentanaPrincipal.this.rellenoActionPerformed(evt);
            }
            else if (evt.getSource() == transparencia) {
                VentanaPrincipal.this.transparenciaActionPerformed(evt);
            }
            else if (evt.getSource() == jComboBox1) {
                VentanaPrincipal.this.jComboBox1ActionPerformed(evt);
            }
            else if (evt.getSource() == botonDisminuir) {
                VentanaPrincipal.this.botonDisminuirActionPerformed(evt);
            }
            else if (evt.getSource() == botonAumentar) {
                VentanaPrincipal.this.botonAumentarActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItem1) {
                VentanaPrincipal.this.jMenuItem1ActionPerformed(evt);
            }
            else if (evt.getSource() == v_barraformas) {
                VentanaPrincipal.this.v_barraformasActionPerformed(evt);
            }
            else if (evt.getSource() == v_barraatributos) {
                VentanaPrincipal.this.v_barraatributosActionPerformed(evt);
            }
            else if (evt.getSource() == boton_discontinuo) {
                VentanaPrincipal.this.boton_discontinuoActionPerformed(evt);
            }
            else if (evt.getSource() == boton_mas_colores) {
                VentanaPrincipal.this.boton_mas_coloresActionPerformed(evt);
            }
            else if (evt.getSource() == jComboBox2) {
                VentanaPrincipal.this.jComboBox2ActionPerformed(evt);
            }
        }

        public void mouseClicked(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == lapiz) {
                VentanaPrincipal.this.lapizMouseClicked(evt);
            }
            else if (evt.getSource() == linea) {
                VentanaPrincipal.this.lineaMouseClicked(evt);
            }
            else if (evt.getSource() == rectangulo) {
                VentanaPrincipal.this.rectanguloMouseClicked(evt);
            }
            else if (evt.getSource() == ovalo) {
                VentanaPrincipal.this.ovaloMouseClicked(evt);
            }
            else if (evt.getSource() == butt_blanco) {
                VentanaPrincipal.this.butt_blancoMouseClicked(evt);
            }
            else if (evt.getSource() == butt_negro) {
                VentanaPrincipal.this.butt_negroMouseClicked(evt);
            }
            else if (evt.getSource() == butt_amarillo) {
                VentanaPrincipal.this.butt_amarilloMouseClicked(evt);
            }
            else if (evt.getSource() == butt_verde) {
                VentanaPrincipal.this.butt_verdeMouseClicked(evt);
            }
            else if (evt.getSource() == butt_rojo) {
                VentanaPrincipal.this.butt_rojoMouseClicked(evt);
            }
            else if (evt.getSource() == butt_azul) {
                VentanaPrincipal.this.butt_azulMouseClicked(evt);
            }
            else if (evt.getSource() == rectangulo_redondo) {
                VentanaPrincipal.this.rectangulo_redondoMouseClicked(evt);
            }
            else if (evt.getSource() == curva) {
                VentanaPrincipal.this.curvaMouseClicked(evt);
            }
        }

        public void mouseEntered(java.awt.event.MouseEvent evt) {
        }

        public void mouseExited(java.awt.event.MouseEvent evt) {
        }

        public void mousePressed(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == selecionar_figura) {
                VentanaPrincipal.this.selecionar_figuraMousePressed(evt);
            }
            else if (evt.getSource() == relleno) {
                VentanaPrincipal.this.rellenoMousePressed(evt);
            }
            else if (evt.getSource() == transparencia) {
                VentanaPrincipal.this.transparenciaMousePressed(evt);
            }
            else if (evt.getSource() == botonRestar) {
                VentanaPrincipal.this.botonRestarMousePressed(evt);
            }
            else if (evt.getSource() == jButton1) {
                VentanaPrincipal.this.jButton1MousePressed(evt);
            }
            else if (evt.getSource() == Nuevo) {
                VentanaPrincipal.this.NuevoMousePressed(evt);
            }
            else if (evt.getSource() == Abrir) {
                VentanaPrincipal.this.AbrirMousePressed(evt);
            }
            else if (evt.getSource() == Guardar) {
                VentanaPrincipal.this.GuardarMousePressed(evt);
            }
            else if (evt.getSource() == jMenuItem1) {
                VentanaPrincipal.this.jMenuItem1MousePressed(evt);
            }
            else if (evt.getSource() == BotonGrabarSonido) {
                VentanaPrincipal.this.BotonGrabarSonidoMousePressed(evt);
            }
            else if (evt.getSource() == botonVideoJMF) {
                VentanaPrincipal.this.botonVideoJMFMousePressed(evt);
            }
            else if (evt.getSource() == v_barraestado) {
                VentanaPrincipal.this.v_barraestadoMousePressed(evt);
            }
            else if (evt.getSource() == v_barraformas) {
                VentanaPrincipal.this.v_barraformasMousePressed(evt);
            }
            else if (evt.getSource() == v_barraatributos) {
                VentanaPrincipal.this.v_barraatributosMousePressed(evt);
            }
        }

        public void mouseReleased(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == Etiqueta_Imagen1) {
                VentanaPrincipal.this.Etiqueta_Imagen1MouseReleased(evt);
            }
        }

        public void mouseDragged(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == barra_umbralizacion) {
                VentanaPrincipal.this.barra_umbralizacionMouseDragged(evt);
            }
        }

        public void mouseMoved(java.awt.event.MouseEvent evt) {
        }

        public void stateChanged(javax.swing.event.ChangeEvent evt) {
            if (evt.getSource() == indicador_grosor) {
                VentanaPrincipal.this.indicador_grosorStateChanged(evt);
            }
            else if (evt.getSource() == barra_brillo) {
                VentanaPrincipal.this.barra_brilloStateChanged(evt);
            }
        }
    }// </editor-fold>//GEN-END:initComponents

    private void lapizMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_lapizMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.setForma(1);
            this.herramienta_seleccionada.setText("lapiz");
            this.repaint();
        }
    }//GEN-LAST:event_lapizMouseClicked


    private void lineaMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_lineaMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.setForma(2);
            this.herramienta_seleccionada.setText("linea");
            this.repaint();
        }
    }//GEN-LAST:event_lineaMouseClicked

    private void rectanguloMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_rectanguloMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.setForma(3);
            this.herramienta_seleccionada.setText("rectangulo");
            this.repaint();
        }
    }//GEN-LAST:event_rectanguloMouseClicked

    private void ovaloMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ovaloMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.setForma(4);
            this.herramienta_seleccionada.setText("ovalo");
            this.repaint();
        }
    }//GEN-LAST:event_ovaloMouseClicked

    private void butt_negroMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_butt_negroMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.getFormaSeleccionda().setColor(Color.BLACK);
            this.repaint();
        }
    }//GEN-LAST:event_butt_negroMouseClicked

    private void butt_rojoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_butt_rojoMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.getFormaSeleccionda().setColor(Color.RED);
            this.repaint();
        }
    }//GEN-LAST:event_butt_rojoMouseClicked

    private void butt_azulMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_butt_azulMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.getFormaSeleccionda().setColor(Color.BLUE);
            this.repaint();
        }
    }//GEN-LAST:event_butt_azulMouseClicked

    private void butt_blancoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_butt_blancoMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.getFormaSeleccionda().setColor(Color.WHITE);
            this.repaint();
        }
    }//GEN-LAST:event_butt_blancoMouseClicked

    private void butt_amarilloMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_butt_amarilloMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.getFormaSeleccionda().setColor(Color.YELLOW);
            this.repaint();
        }
    }//GEN-LAST:event_butt_amarilloMouseClicked

    private void butt_verdeMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_butt_verdeMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.getFormaSeleccionda().setColor(Color.GREEN);
            this.repaint();
        }
    }//GEN-LAST:event_butt_verdeMouseClicked

    private void indicador_grosorStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_indicador_grosorStateChanged
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();

            if ((int) this.indicador_grosor.getValue() < 0) {
                this.indicador_grosor.setValue(0);
            } else {
                lienzo.getFormaSeleccionda().setGrosor((int) this.indicador_grosor.getValue());
                this.repaint();
            }
        }
    }//GEN-LAST:event_indicador_grosorStateChanged

    private void NuevoMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_NuevoMousePressed
        VentanaInterna vi = new VentanaInterna(this);
        escritorio.add(vi);
        vi.setVisible(true);
    }//GEN-LAST:event_NuevoMousePressed

    private void AbrirMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_AbrirMousePressed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {
            try {
                File f = dlg.getSelectedFile();
                this.file = f;
                if (ImageIO.read(f) != null) {
                    BufferedImage img = ImageIO.read(f);
                    VentanaInterna vi = new VentanaInterna(this);
                    vi.setTitle("Editando Imagen" + f.getName());
                    vi.getLienzo().CrearImagen(img);
                    this.escritorio.add(vi);
                    vi.setVisible(true);
                }
            } catch (Exception ex) {
                System.err.println("Error al leer la imagen");
            }
        }
    }//GEN-LAST:event_AbrirMousePressed

    private void GuardarMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_GuardarMousePressed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {
            File f = dlg.getSelectedFile();
            VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
            if (vi.getLienzo().getImagen() != null) {
                if (vi.getLienzo().getImagen().getImagen() != null) {
                    vi.getLienzo().getImagen().guardarImagen(vi.getLienzo().getFormas());
                    try {
                        ImageIO.write(vi.getLienzo().getImagen().getImagen(), "jpg", f);
                    } catch (IOException ex) {
                        Logger.getLogger(VentanaPrincipal.class.getName()).log(Level.SEVERE, null, ex);
                    }

                }
            }
        }
    }//GEN-LAST:event_GuardarMousePressed

    private void v_barraformasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_v_barraformasActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_v_barraformasActionPerformed

    private void v_barraatributosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_v_barraatributosActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_v_barraatributosActionPerformed

    private void v_barraestadoMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_v_barraestadoMousePressed
        if (!this.v_barraestado.getState()) {
            this.herramienta_seleccionada.setVisible(true);
        } else {
            this.herramienta_seleccionada.setVisible(false);// TODO add your handling code here:
        }
    }//GEN-LAST:event_v_barraestadoMousePressed

    private void v_barraformasMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_v_barraformasMousePressed
        if (!this.v_barraformas.getState()) {
            this.Barra_de_herramientas.setVisible(true);
        } else {
            this.Barra_de_herramientas.setVisible(false);// TODO add your handling code here:
        }
    }//GEN-LAST:event_v_barraformasMousePressed

    private void v_barraatributosMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_v_barraatributosMousePressed
        if (!this.v_barraatributos.getState()) {
            this.opciones_dibujo.setVisible(true);
        } else {
            this.opciones_dibujo.setVisible(false);// TODO add your handling code here:
        }
    }//GEN-LAST:event_v_barraatributosMousePressed

    private void rellenoMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_rellenoMousePressed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            if (lienzo.getFormaSeleccionda() instanceof Rectangulo) {
                if (((Rectangulo) lienzo.getFormaSeleccionda()).getRelleno()) {
                    ((Rectangulo) lienzo.getFormaSeleccionda()).setRelleno(false);
                } else {
                    ((Rectangulo) lienzo.getFormaSeleccionda()).setRelleno(true);
                }
            }
            if (lienzo.getFormaSeleccionda() instanceof Elipse) {
                if (((Elipse) lienzo.getFormaSeleccionda()).getRelleno()) {
                    ((Elipse) lienzo.getFormaSeleccionda()).setRelleno(false);
                } else {
                    ((Elipse) lienzo.getFormaSeleccionda()).setRelleno(true);
                }
            }
            lienzo.repaint();
        }          // TODO add your handling code here:
    }//GEN-LAST:event_rellenoMousePressed

    private void transparenciaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_transparenciaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_transparenciaActionPerformed

    private void transparenciaMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_transparenciaMousePressed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            if (lienzo.getFormaSeleccionda() instanceof Rectangulo) {
                if (((Rectangulo) lienzo.getFormaSeleccionda()).getTransparencia()) {
                    System.out.println("Aplico transparencia al rectangulo");
                    ((Rectangulo) lienzo.getFormaSeleccionda()).setTransparencia(false);
                    ((Rectangulo) lienzo.getFormaSeleccionda()).aplicarTransparencia();
                } else {
                    System.out.println("Desago transparencia al rectangulo");
                    ((Rectangulo) lienzo.getFormaSeleccionda()).setTransparencia(true);
                    ((Rectangulo) lienzo.getFormaSeleccionda()).aplicarTransparencia();
                }
            }
            if (lienzo.getFormaSeleccionda() instanceof Elipse) {
                if (((Elipse) lienzo.getFormaSeleccionda()).getTransparencia()) {
                    System.out.println("Aplico transparencia a la elipse");
                    ((Elipse) lienzo.getFormaSeleccionda()).setTransparencia(false);
                    ((Elipse) lienzo.getFormaSeleccionda()).aplicarTransparencia();
                } else {
                    System.out.println("Desago transparencia a la elipse");
                    ((Elipse) lienzo.getFormaSeleccionda()).setTransparencia(true);
                    ((Elipse) lienzo.getFormaSeleccionda()).aplicarTransparencia();
                }
            }
            lienzo.repaint();
        }

    }//GEN-LAST:event_transparenciaMousePressed

    private void selecionar_figuraMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_selecionar_figuraMousePressed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        System.out.println(" Seleccionado modo editar, vp");
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();

            if (lienzo.getSelecionar()) {
                lienzo.setSelecionar(false);
            } else {
                lienzo.setSelecionar(true);
            }
        }        // TODO add your handling code here:
    }//GEN-LAST:event_selecionar_figuraMousePressed

    private void jComboBox1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBox1ActionPerformed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        Lienzo lienzo = vi.getLienzo();

        if (lienzo != null && lienzo.getImagen() != null) {
            if (this.jComboBox1.getSelectedItem().toString() == "No aplicar ninguno") {
                if (lienzo.getImagen().getImagenTemporal() != null) {
                    lienzo.getImagen().setImagenTemporal(null);
                    lienzo.repaint();
                }
            } else if (this.jComboBox1.getSelectedItem().toString() == "emborramiento media") {
                lienzo.getImagen().setConvolucion(0);
            } else if (this.jComboBox1.getSelectedItem().toString() == "emborramiento binomial") {
                lienzo.getImagen().setConvolucion(1);
            } else if (this.jComboBox1.getSelectedItem().toString() == "enfoque") {
                lienzo.getImagen().setConvolucion(2);
            } else if (this.jComboBox1.getSelectedItem().toString() == "relieve") {
                lienzo.getImagen().setConvolucion(3);
            } else if (this.jComboBox1.getSelectedItem().toString() == "detector fronteras") {
                lienzo.getImagen().setConvolucion(4);
            } else if (this.jComboBox1.getSelectedItem().toString() == "contraste") {
                lienzo.getImagen().setLookUpOp(1);
            } else if (this.jComboBox1.getSelectedItem().toString() == "iluminación") {
                lienzo.getImagen().setLookUpOp(2);
            } else if (this.jComboBox1.getSelectedItem().toString() == "oscurecer") {
                lienzo.getImagen().setLookUpOp(3);
            }
        }
    }//GEN-LAST:event_jComboBox1ActionPerformed

    private void barra_brilloStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_barra_brilloStateChanged
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        Lienzo lienzo = vi.getLienzo();

        if (lienzo != null && lienzo.getImagen() != null) {
            lienzo.getImagen().setBrillo(this.barra_brillo.getValue());
        }
    }//GEN-LAST:event_barra_brilloStateChanged

    private void botonAumentarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonAumentarActionPerformed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        Lienzo lienzo = vi.getLienzo();
        if (lienzo != null) {
            BufferedImage imagenSource = null;
            if (lienzo.getImagen().getImagen() != null) {
                imagenSource = lienzo.getImagen().getImagen();
            }
            if (imagenSource != null && lienzo.getImagen().getEscala() < 3) {
                lienzo.getImagen().setEscala(lienzo.getImagen().getEscala() + 1.25);
                AffineTransform at = AffineTransform.getScaleInstance(lienzo.getImagen().getEscala(),
                        lienzo.getImagen().getEscala());
                AffineTransformOp atop;
                atop = new AffineTransformOp(at, AffineTransformOp.TYPE_BILINEAR);
                BufferedImage imagendest = atop.filter(imagenSource, null);
                if (imagendest != null) {
                    vi.getLienzo().getImagen().setImagenTemporal(imagendest);
                    vi.getLienzo().repaint();
                }
            }
        }
    }//GEN-LAST:event_botonAumentarActionPerformed

    private void botonDisminuirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonDisminuirActionPerformed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        Lienzo lienzo = vi.getLienzo();
        if (lienzo != null) {
            BufferedImage imagenSource = null;
            if (lienzo.getImagen().getImagen() != null) {
                imagenSource = lienzo.getImagen().getImagen();
            }
            if (imagenSource != null && lienzo.getImagen().getEscala() > 0.75) {
                lienzo.getImagen().setEscala(lienzo.getImagen().getEscala() - 0.75);
                AffineTransform at = AffineTransform.getScaleInstance(lienzo.getImagen().getEscala(),
                        lienzo.getImagen().getEscala());
                AffineTransformOp atop;
                atop = new AffineTransformOp(at, AffineTransformOp.TYPE_BILINEAR);
                BufferedImage imagendest = atop.filter(imagenSource, null);
                if (imagendest != null) {
                    vi.getLienzo().getImagen().setImagenTemporal(imagendest);
                    vi.getLienzo().repaint();
                }
            }
        }
    }//GEN-LAST:event_botonDisminuirActionPerformed

    private void barra_umbralizacionMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_barra_umbralizacionMouseDragged
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        Lienzo lienzo = null;
        if (vi != null) {
            lienzo = vi.getLienzo();
        }
        if (lienzo != null) {
            lienzo.getUmbral().setUmbral(this.barra_umbralizacion.getValue());
            if (lienzo.getImagen().getImagen() != null) {
                lienzo.getImagen().setImagenTemporal(lienzo.getUmbral().filter(lienzo.getImagen().getImagen()));
                lienzo.repaint();
            }
        }

    }//GEN-LAST:event_barra_umbralizacionMouseDragged

    private void botonRestarMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botonRestarMousePressed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            BufferedImage imgRight = vi.getLienzo().getImagen().getImagen();
            BufferedImage imgLeft = null;
            JFileChooser dlg = new JFileChooser();
            int resp = dlg.showOpenDialog(this);
            if (resp == JFileChooser.APPROVE_OPTION) {
                try {
                    File f = dlg.getSelectedFile();
                    this.file = f;
                    if (ImageIO.read(f) != null) {
                        imgLeft = ImageIO.read(f);
                    }
                } catch (Exception ex) {
                    System.err.println("Error al leer la imagen");
                }
            }
            if (imgLeft != null && imgRight != null) {
                RestaOp op = new RestaOp(imgLeft);
                BufferedImage imgdest = op.filter(imgRight, null);
                if (imgdest != null) {
                    vi.getLienzo().getImagen().setImagenTemporal(imgdest);
                    vi.getLienzo().repaint();
                }
            }
        }
        // TODO add your handling code here:
    }//GEN-LAST:event_botonRestarMousePressed

    private void jMenuItem1MousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jMenuItem1MousePressed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {

            File f = dlg.getSelectedFile();
            this.file = f;
            VentanaInternaAudio vi = new VentanaInternaAudio(f);
            vi.setTitle("Reproducir archivo : " + f.getName());
            this.escritorio.add(vi);
            vi.setVisible(true);

        }
    }//GEN-LAST:event_jMenuItem1MousePressed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void BotonGrabarSonidoMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BotonGrabarSonidoMousePressed

        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {

            File f = dlg.getSelectedFile();
            this.file = f;
            VentanaInternaGrabacion vi = new VentanaInternaGrabacion(f);
            vi.setTitle("Reproducir archivo : " + f.getName());
            this.escritorio.add(vi);
            vi.setVisible(true);

        }// TODO add your handling code here:
    }//GEN-LAST:event_BotonGrabarSonidoMousePressed

    private void botonVideoJMFMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botonVideoJMFMousePressed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {
            File f = dlg.getSelectedFile();
            VentanaInternaJMF vi = VentanaInternaJMF.getInstance(f, this);
            this.v_jmf = vi;
            this.escritorio.add(vi);
            vi.setVisible(true);
        }

    }//GEN-LAST:event_botonVideoJMFMousePressed

    private void Etiqueta_Imagen1MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Etiqueta_Imagen1MouseReleased
        // TODO add your handling code here:
    }//GEN-LAST:event_Etiqueta_Imagen1MouseReleased

    private void jButton1MousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton1MousePressed
        FrameGrabbingControl fgc;
        String claseCtr = "javax.media.control.FrameGrabbingControl";
        fgc = (FrameGrabbingControl) this.v_jmf.player_jmf.getControl(claseCtr);
        if (fgc != null) {
            Buffer bufferFrame = fgc.grabFrame();
            BufferToImage bti;
            bti = new BufferToImage((VideoFormat) bufferFrame.getFormat());
            Image img = bti.createImage(bufferFrame);
            VentanaInterna vi = new VentanaInterna(this);
            vi.getLienzo().CrearImagen((BufferedImage) img);
            this.escritorio.add(vi);
            vi.setVisible(true);
        }// TODO add your handling code here:
    }//GEN-LAST:event_jButton1MousePressed

    private void rellenoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rellenoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_rellenoActionPerformed

    private void boton_discontinuoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_boton_discontinuoActionPerformed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();      // TODO add your handling code here:
        if (vi != null) {
            if (vi.getLienzo().getFormaSeleccionda() != null) {
                vi.getLienzo().getFormaSeleccionda().set_discontinuo(!this.boton_discontinuo.isSelected());
                vi.getLienzo().repaint();
            }
        }
    }//GEN-LAST:event_boton_discontinuoActionPerformed

    private void boton_mas_coloresActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_boton_mas_coloresActionPerformed
        Color color = (JColorChooser.showDialog(this, "Seleccione el color", Color.white));
        if (color != null) {
            VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
            if (vi != null && vi.getLienzo().getFormaSeleccionda() != null) {
                vi.getLienzo().getFormaSeleccionda().setColor(color);
                vi.getLienzo().repaint();
            }
        }        // TODO add your handling code here:
    }//GEN-LAST:event_boton_mas_coloresActionPerformed

    private void jComboBox2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBox2ActionPerformed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();

        if (vi != null) {
            if (this.jComboBox2.getSelectedItem().toString() == "Diagonal") {
                System.out.println("Comprobamos horizontal");
                if (vi.getLienzo().getFormaSeleccionda() != null) {
                    if (vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Rectangle2D.Double
                            || vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Ellipse2D.Double) {
                        Color color1 = (JColorChooser.showDialog(this, "Seleccione el color 1 del degradado", Color.white));
                        Color color2 = (JColorChooser.showDialog(this, "Seleccione el color 2 del degradado", Color.white));
                        vi.getLienzo().getFormaSeleccionda().setColorGradiente(color1, color2);
                        vi.getLienzo().getFormaSeleccionda().setGradienteDiagonal(true);
                        vi.getLienzo().getFormaSeleccionda().setGradienteVertical(false);
                        vi.getLienzo().getFormaSeleccionda().setGradienteHorizontal(false);
                        vi.getLienzo().repaint();
                    }
                }
            }
            if (this.jComboBox2.getSelectedItem().toString() == "Horizontal") {
                System.out.println("Comprobamos horizontal");
                if (vi.getLienzo().getFormaSeleccionda() != null) {
                    if (vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Rectangle2D.Double
                            || vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Ellipse2D.Double) {
                        Color color1 = (JColorChooser.showDialog(this, "Seleccione el color 1 del degradado", Color.white));
                        Color color2 = (JColorChooser.showDialog(this, "Seleccione el color 2 del degradado", Color.white));
                        vi.getLienzo().getFormaSeleccionda().setColorGradiente(color1, color2);
                        vi.getLienzo().getFormaSeleccionda().setGradienteDiagonal(false);
                        vi.getLienzo().getFormaSeleccionda().setGradienteVertical(false);
                        vi.getLienzo().getFormaSeleccionda().setGradienteHorizontal(true);
                        vi.getLienzo().repaint();
                    }
                }
            }

            if (this.jComboBox2.getSelectedItem().toString() == "Vertical") {
                if (vi.getLienzo().getFormaSeleccionda() != null) {
                    if (vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Rectangle2D.Double
                            || vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Ellipse2D.Double) {
                        Color color1 = (JColorChooser.showDialog(this, "Seleccione el color 2 del degradado", Color.white));
                        Color color2 = (JColorChooser.showDialog(this, "Seleccione el color 2 del degradado", Color.white));
                        vi.getLienzo().getFormaSeleccionda().setColorGradiente(color1, color2);
                        vi.getLienzo().getFormaSeleccionda().setGradienteDiagonal(false);
                        vi.getLienzo().getFormaSeleccionda().setGradienteVertical(true);
                        vi.getLienzo().getFormaSeleccionda().setGradienteHorizontal(false);
                        vi.getLienzo().repaint();
                    }
                }
            }
            if (this.jComboBox2.getSelectedItem().toString() == "Ninguno") {
                if (vi.getLienzo().getFormaSeleccionda() != null) {
                    if (vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Rectangle2D.Double
                            || vi.getLienzo().getFormaSeleccionda().getFigura() instanceof Ellipse2D.Double) {
                        vi.getLienzo().getFormaSeleccionda().setColorGradiente(null, null);
                        vi.getLienzo().getFormaSeleccionda().setGradienteHorizontal(false);
                        vi.getLienzo().getFormaSeleccionda().setGradienteVertical(false);
                        vi.getLienzo().getFormaSeleccionda().setGradienteDiagonal(false);
                    }
                    vi.getLienzo().repaint();
                }
            }// TODO add your handling code here:
        }
    }//GEN-LAST:event_jComboBox2ActionPerformed

    private void rectangulo_redondoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_rectangulo_redondoMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.setForma(5);
            this.repaint();
        }        // TODO add your handling code here:
    }//GEN-LAST:event_rectangulo_redondoMouseClicked

    private void curvaMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_curvaMouseClicked
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            Lienzo lienzo = vi.getLienzo();
            lienzo.setForma(6);
            this.repaint();
        }    
    }//GEN-LAST:event_curvaMouseClicked

    public javax.swing.JRadioButton getBotonSeleccionar() {
        return this.selecionar_figura;
    }

    public javax.swing.JRadioButton getBotonRelleno() {
        return this.relleno;
    }

    public javax.swing.JRadioButton getBotonTransparencia() {
        return this.transparencia;
    }

    public javax.swing.JSpinner getIndicadorGrosor() {
        return this.indicador_grosor;
    }


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem Abrir;
    private javax.swing.JMenu Archivo;
    private javax.swing.JToolBar Barra_de_herramientas;
    private javax.swing.JMenuItem BotonGrabarSonido;
    private javax.swing.JMenu Edicion;
    private javax.swing.JLabel Etiqueta_Imagen1;
    private javax.swing.JLabel Etiqueta_Imagen2;
    private javax.swing.JMenuItem Guardar;
    private javax.swing.JMenuItem Nuevo;
    private javax.swing.JSlider barra_brillo;
    private javax.swing.JSlider barra_umbralizacion;
    private javax.swing.JButton botonAumentar;
    private javax.swing.JButton botonDisminuir;
    private javax.swing.JToggleButton botonRestar;
    private javax.swing.JMenuItem botonVideoJMF;
    private javax.swing.JRadioButton boton_discontinuo;
    private javax.swing.JButton boton_mas_colores;
    private javax.swing.JButton butt_amarillo;
    private javax.swing.JButton butt_azul;
    private javax.swing.JButton butt_blanco;
    private javax.swing.JButton butt_negro;
    private javax.swing.JButton butt_rojo;
    private javax.swing.JButton butt_verde;
    private javax.swing.JButton curva;
    private javax.swing.JPanel dibujo;
    private javax.swing.JDesktopPane escritorio;
    private javax.swing.JLabel etiqueta_brillo;
    private javax.swing.JLabel etiqueta_umbral;
    private javax.swing.JPanel grosor;
    private javax.swing.JPanel grosor_relleno;
    private javax.swing.JLabel herramienta_seleccionada;
    private javax.swing.JSpinner indicador_grosor;
    private javax.swing.JButton jButton1;
    private javax.swing.JComboBox jComboBox1;
    private javax.swing.JComboBox jComboBox2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JButton lapiz;
    private javax.swing.JButton linea;
    private javax.swing.JMenuBar menu_opciones_archivo;
    private javax.swing.JPanel opciones_dibujo;
    private javax.swing.JPanel operaciones_imagen;
    private javax.swing.JButton ovalo;
    private javax.swing.JPanel panel_colores;
    private javax.swing.JPanel panel_opciones_figura;
    private javax.swing.JButton rectangulo;
    private javax.swing.JButton rectangulo_redondo;
    private javax.swing.JRadioButton relleno;
    private javax.swing.JPanel relleno_editar;
    private javax.swing.JRadioButton selecionar_figura;
    private javax.swing.JLabel texto_grosor;
    private javax.swing.JRadioButton transparencia;
    private javax.swing.JCheckBoxMenuItem v_barraatributos;
    private javax.swing.JCheckBoxMenuItem v_barraestado;
    private javax.swing.JCheckBoxMenuItem v_barraformas;
    // End of variables declaration//GEN-END:variables

}
