import { Gauge, Radio, Trophy } from "lucide-react";
import { academicExperiences } from "@/data/academic";
import { SectionTitle } from "../ui/SectionTitle";
import { TechnologyBadge } from "../ui/TechnologyBadge";

export function Academic() {
  return <section className="section academic-section shell" id="academico">
    <SectionTitle eyebrow="ALÉM DA INDÚSTRIA" title="Engenharia que começou na prática." description="Competição, extensão e tecnologia como espaços de experimentação, liderança e impacto." />
    <div className="academic-grid">{academicExperiences.map((item) => <article className={item.featured ? "academic-card featured" : "academic-card"} key={item.name}>
      <div className="academic-card-top"><span className="academic-icon">{item.featured ? <Gauge size={22}/> : <Radio size={22}/>}</span><p>{item.period}</p></div>
      <p className="eyebrow">{item.context}</p><h3>{item.name}</h3><p className="academic-institution">{item.institution}</p><p className="academic-roles">{item.roles.join(" → ")}</p>
      <p className="academic-description">{item.description}</p><div className="academic-impact"><Trophy size={17} aria-hidden="true"/><p>{item.impact}</p></div>
      <div className="badge-list">{item.technologies.map((technology) => <TechnologyBadge key={technology}>{technology}</TechnologyBadge>)}</div>
    </article>)}</div>
  </section>;
}
