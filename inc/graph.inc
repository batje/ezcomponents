<?php
include_once libraries_get_path('ezcomponents') .'/Base/src/base.php';
/**
 * Autoload ezc classes 
 * 
 * @param string $className 
 */
function __autoload( $className )
{
    ezcBase::autoload( $className );
}

class tutorialCustomPalette extends ezcGraphPalette
{
    protected $axisColor = '#000000';

    protected $majorGridColor = '#000000BB';

    protected $dataSetColor = array(
        '#4E9A0688',
        '#3465A4DD',
        '#F5790Ee0',
        '#F5777Ee0',
        '#F57788e0'
        );

    protected $dataSetSymbol = array(
        ezcGraph::BULLET,
    );

    protected $fontName = 'sans-serif';

    protected $fontColor = '#555753';
}



class DrupalCustomPalette extends ezcGraphPalette {
  
    var $axisColor = '#000000';

    var $majorGridColor = '#000000BB';

    protected $dataSetColor = array(
        '#4E9A0688',
        '#3465A4DD',
        '#F5790Ee0',
        '#F5777Ee0',
        '#F57788e0'
        );
    
    var $dataSetSymbol = array(
        ezcGraph::BULLET,
    );

    var $fontName = 'sans-serif';

    var $fontColor = '#555753';
}



class ChartsGraphsEz extends ChartsGraphsCanvas {
 
  var $type = 'line';
  var $width = 450;
  var $height = 200;
  var $title = '';
 
/*  public function set_data($rows, $x_labels) {
    $this->series = $rows;
    $this->x_labels = $x_labels; 
  }
 */
  public function get_chart() {
       
    //-- some logic that implements engine and produces HTML

    $graph = new ezcGraphBarChart();
    $graph->legend = false;
    $graph->title = $this->title;

    /* Very important: load the dataSetColor array before you add data!! */
    $palette = new DrupalCustomPalette();
    $palette->axisColor = "#000000FF"; 
    $palette->majorGridColor = "#00F000FF";
    $palette->chartBackground = $this->colour ? $this->colour : "#FFFFFF";
    $palette->dataSetColor = $this->series_colours;
    $graph->palette = $palette;
    
    //$graph->renderer = new ezcGraphRenderer3d();
    
    drupal_set_message("backcolor " . $this->colour);
        
    $ylegend = $this->y_legend ? $this->y_legend : 'x';
 
    foreach ($this->x_labels as $key => $label) {
       
       $series_columns = array_keys($this->series);
       $series_column = $series_columns[0];
       
       $graph->data[$label] = new ezcGraphArrayDataSet( array(
         $ylegend => $this->series[$series_column][$key],
       ) ); 
       $graph->data[$label]->highlight = true; 
    }      
    /*
     $graph->data['Press'] = new ezcGraphArrayDataSet( array(
 $this->y_legend => 191,
 ) ); 
     $graph->data['Public'] = new ezcGraphArrayDataSet( array(
 $this->y_legend => 113,
 ) ); */
 
//  $graph->options->fillLines = 210;

 
/*  $graph->data['Demgroup']->highlight = true; 
  $graph->data['Public']->highlight = true; 
  $graph->data['CEW-IT']->highlight = true; 
  $graph->data['Press']->highlight = true; 
  */   
  $graph->options->highlightSize = 8;

  $graph->options->highlightFont = file_directory_path() . '/Helvetica.ttf'; 
  $graph->options->highlightFont->background = '#EEEEECFF';
// $graph->options->highlightFont->border = '#000000';
// $graph->options->highlightFont->borderWidth = 1; 
 
// $graph->options->stackBars = true;
  
 
    
  /*  $graph->yAxis->axisSpace = 0.1; 
    $graph->xAxis->axisSpace = 0.1;
    $graph->yAxis->outerAxisSpace = 0.1;  
    $graph->xAxis->maxArrowHeadSize = 50;
    $graph->xAxis->nullPosition = 50;
    $graph->xAxis->padding = 50;
    $graph->yAxis->padding = 50;
    $graph->xAxis->margin = 50;
    $graph->yAxis->margin = 50;
    $graph->xAxis->labelCount = 50;*/
//    $graph->xAxis = new ezcGraphChartElementNumericAxis();
 //   $graph->xAxis->min = 0;
  //  $graph->xAxis->max = 1;
     
    //    $graph->xAxis->position = 4;
    //    $graph->xAxis = NULL;
    //    $graph->xAxis->chartPosition = .9;
//    $graph->xAxis->color = "#000000FF";
//    $graph->xAxis->axisLabelRenderer = new ezcGraphAxisNoLabelRenderer();
//    $graph->yAxis->axisLabelRenderer = new ezcGraphAxisNoLabelRenderer();
    
  //  $palette = new ezcGraphPaletteEzGreen();
//    $palette = new tutorialCustomPalette();
    // lets make axis etc transparent
    
//    $palette->font = file_directory_path() . '/Helvetica.ttf'; 
      
    
    
    $graph->options->font = file_directory_path() . '/Helvetica.ttf'; 
    $graph->options->font->minFontSize = 5;
    $graph->options->font->maxFontSize = 5;
    # // Generate a Jpeg with lower quality. The default settings result in a image
# // with better quality.
# //
# // The reduction of the supersampling to 1 will result in no anti aliasing of
# // the image. JPEG is not the optimal format for grapics, PNG is far better for
# // this kind of images.
   $graph->driver = new ezcGraphGdDriver(); 
   $graph->driver->options->supersampling = 1;
   $graph->driver->options->jpegQuality = 100;
   $graph->driver->options->imageFormat = IMG_PNG; 
//    $graph->data["jan"] = new ezcGraphArrayDataSet( "12" ); 
//    $graph->data["reinier"] = new ezcGraphArrayDataSet( "14" ); 
    $graph->render( $this->width, $this->height, file_directory_path() . '/tutorial_bar_chart.png' );
    
    return '<img src ="'. file_directory_path() . '/tutorial_bar_chart.png'. '" />';
    
  }        
  
}