// Build the metadata panel
function buildMetadata(sample) {
  d3.json("https://static.bc-edx.com/data/dl-1-2/m14/lms/starter/samples.json").then((data) => {

    // get the metadata field
    let metadata = data.metadata; 

    // Filter the metadata for the object with the desired sample number

    let res = metadata.filter(metadata => metadata.id == sample); 

    console.log(res); 

    let Dobject; 
    if (res.length > 0 )
    {  
      Dobject = res[0]; 
    }
    
    //console.log(data)


    // Use d3 to select the panel with id of `#sample-metadata`
     let panel = d3.select("#sample-metadata"); 

    //console.log(panel); 

    // Use `.html("") to clear any existing metadata
    panel.html(""); 

    // Inside a loop, you will need to use d3 to append new
    // tags for each key-value in the filtered metadata.
    if (Dobject)
    {
      let keys = Object.keys(Dobject);
    for (let i = 0; i < keys.length; i++) 
    {
      let key_loop = keys[i];
      let v_loop = Dobject[key_loop];

      panel.append("p").text(`${key_loop}: ${v_loop}`); 
    }


  }
  });
}

// function to build both charts
function buildCharts(sample) {
  d3.json("https://static.bc-edx.com/data/dl-1-2/m14/lms/starter/samples.json").then((data) => {

    // Get the samples field
    let samples = data.samples;

    // Filter the samples for the object with the desired sample number
    let res2 = samples.filter(samples_f => samples_f.id == sample); 

    //console.log(res2); 

    // Get the otu_ids, otu_labels, and sample_values
    let Dobject2;
    let otu_ids; 
    let otu_labels;
    let sample_values;
    if (res2.length > 0 )
    {  
      Dobject2 = res2[0];
      otu_ids = Dobject2.otu_ids; 
      otu_labels = Dobject2.otu_labels;
      sample_values = Dobject2.sample_values; 
    }
      
    //  console.log(data);
    // Build a Bubble Chart
    let trace = 
    {
      x: otu_ids.slice(0,5),
      y: sample_values.slice(0,5), 
      text: otu_labels.slice(0,5), 
      mode:'markers', 
      marker: 
      {
      color: otu_ids,
      size: sample_values, 
      opacity: 0.4, 
      colorscale: 'YlGnBu', 
    }
    }; 

    let b_data = [trace]; 

    let layout =
     {
      title: "bubble chart", 
      xaxis: {title: "otu_ids"},  
      yaxis: {title: "values"}
    };

    // Render the Bubble Chart
    Plotly.newPlot('bubble', b_data, layout); 

    // For the Bar Chart, map the otu_ids to a list of strings for your yticks
    let lis = otu_ids.slice(0,5).map(id => `otu ${id}`); 

    let trace2 = 
    {
      x: lis,  
      y: sample_values.slice(0,5),
      text: otu_labels.slice(0,5), 
      type: 'bar'
      
    }; 

    let b2_data = [trace2];

    let layout2 =
     {
      title: "bar chart", 
      xaxis: {title: "otu_ids"},  
      yaxis: {title: "values"}
    };

    Plotly.newPlot('bar', b2_data, layout2);


    // Build a Bar Chart
    // Don't forget to slice and reverse the input data appropriately


    // Render the Bar Chart

  });
}

// Function to run on page load
function init() {
  d3.json("https://static.bc-edx.com/data/dl-1-2/m14/lms/starter/samples.json").then((data) => {

    // Get the names field
    let data_names = data.names

    // Use d3 to select the dropdown with id of `#selDataset`
    let dropdownMenu = d3.select("#selDataset");
    


    // Use the list of sample names to populate the select options

    for (let i = 0;i < data_names.length; i++)
    {
      dropdownMenu.append("option").text(data_names[i]).property("value", data_names[i])
 
    };
    

    // Hint: Inside a loop, you will need to use d3 to append a new option for each sample name.



    dropdownMenu.on("change", optionChanged);
    // Get the first sample from the list
    let first = data_names[0]; 

    // Build charts and metadata panel with the first sample
    buildMetadata(first); 
    buildCharts(first);
  })
}

// Function for event listener
function optionChanged(newSample) {
  // Build charts and metadata panel each time a new sample is selected

  console.log(newSample); 
  newSample = d3.select("#selDataset").property("value"); 
  // console.log(newSample); 
  buildMetadata(newSample); 
  buildCharts(newSample);

}

// Initialize the dashboard
init();
